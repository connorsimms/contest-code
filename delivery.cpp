#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<pair<int, int>> l;
  vector<pair<int, int>> r;

  for (int i = 0; i < N; ++i) {
    int p, t;
    cin >> p >> t;

    if (p < 0)
      l.emplace_back(-p, t);
    if (p > 0)
      r.emplace_back(p, t);
  }

  reverse(r.begin(), r.end());

  long long ans = 0;
  int pos = 0;
  int cap = K;

  auto comp = [&](vector<pair<int, int>> v) {
    for (int i = 0; i < v.size();) {
      auto &[p, t] = v[i];

      ans += abs(p - pos);
      pos = p;

      int fill = min(t, cap);

      t -= fill;
      cap -= fill;

      if (t != 0) {
        cap = K;
        ans += pos * 2;
        continue;
      }

      if (cap == 0) {
        ans += pos;
        pos = 0;
        cap = K;
      }

      ++i;
    }
  };

  comp(l);
  ans += pos;

  pos = 0;
  cap = K;

  comp(r);
  ans += pos;

  cout << ans << '\n';
}
