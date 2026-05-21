#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main()
{
  int N, L, W; 
  while (cin >> N >> L >> W)
  {
    vector<pair<double,double>> s;

    for (int i = 0 ; i < N; ++i)
    {
      long long x, r; cin >> x >> r;

      double v = r * r - (W / 2.0) * (W / 2.0);

      if (v < 0) { continue; }

      double dx = sqrt(v);

      s.emplace_back(x - dx, x + dx);
    }

    if (s.empty())
    {
      cout << -1 << '\n';
      continue;
    }

    sort(s.begin(), s.end(), [](const auto& a, const auto& b) {
      if (a.first == b.first) return a.second > b.second;
      return a.first < b.first;
    });

    int ans = 0;
    double pos = 0;

    N = s.size();

    for (int i = 0 ; i < N; ++i)
    {
      if (pos >= L) { break; }

      if (s[i].second < pos) { continue; }
      
      if (s[i].first > pos)
      {
        ans = -1;
        break;
      }

      int max_id = -1;
      double max_r = -1.0;
      for (int j = i ; j < N && s[j].first <= pos; ++j)
      {
        if (s[j].second > max_r)
        {
          max_r = s[j].second;
          max_id = j;
        }
      }

      if (max_id == -1)
      {
        ans = -1;
        break;
      }

      ++ans;
      i = max_id;
      pos = max_r;
    }

    if (pos < L)
    {
      ans = -1;
    }

    cout << ans << '\n';
  }
}
