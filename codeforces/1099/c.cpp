#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    map<int, int> f;

    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      ++f[x];
    }

    int ans = 0;

    for (auto it = f.rbegin(); it != next(f.rend(), -2); ++it) {
      auto [k, v] = *it;

      if (k & 1) {
        f[(k + 1) / 2] += f[k];
        ans += f[k];
        f[k] = 0;
      } else {
        f[k / 2] += f[k];
        ans += f[k];
        f[k] = 0;
      }
    }

    cout << ans << '\n';
  }
}
