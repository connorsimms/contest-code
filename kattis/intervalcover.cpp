#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

int main()
{
  double a, b;
  while (cin >> a >> b)
 {
    int n; cin >> n;

    vector<tuple<double,double,int>> v;

    int ans = 0;
    bool cover = false;

    for (int i = 0; i < n; ++i)
    {
      double x, y; cin >> x >> y;

      if (cover) continue;

      if (x <= a && y >= b)
      {
        cout << 1 << '\n';
        cout << i << '\n';
        cover = true;
      }

      v.emplace_back(x, y, i);
    }

    if (cover) continue;

    sort(v.begin(), v.end(), [] (const auto& t1, const auto& t2) {
        auto& [x1, y1, z1] = t1;
        auto& [x2, y2, z2] = t2;

        if (x1 == x2) return y1 > y2;
        return x1 < x2;
    });

    double pos = a;

    vector<int> res;

    for (int i = 0; i < v.size() && pos < b; ++i)
    {
      auto& [x1, y1, idx1] = v[i];

      if (y1 < pos) continue;

      int bestIdx = -1;
      int jumpTo = -1;
      double best = pos;

      for (int j = i; j < v.size(); ++j)
      {
        auto& [x2, y2, idx2] = v[j];

        if (x2 > pos) break;

        if (y2 > best)
        {
          bestIdx = idx2;
          best = y2;
        }

          jumpTo = j;
      }

      if (bestIdx == -1) break;

      i = jumpTo;
      res.push_back(bestIdx);
      pos = best;
      ++ans;
    }

    if (pos < b || ans == 0)
    {
      cout << "impossible\n";
    }
    else
    {
      cout << ans << '\n';
      for (auto i : res)
      {
        cout << i << ' ';
      }
      cout << '\n';
    }
  }
}
