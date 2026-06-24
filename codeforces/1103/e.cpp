#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<vector<tuple<int, int, int>>> v(n / 2 + 1);

  vector<vector<int>> mn(n, vector<int>(n)), mx(n, vector<int>(n));

  for (int i = 0; i < n; ++i) {
    int x = a[i];
    int y = a[i];
    for (int j = i; j < n; ++j) {
      x = min(x, a[j]);
      y = max(y, a[j]);
      mn[i][j] = x;
      mx[i][j] = y;
    }
  }

  vector<int> f(n + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (f[a[j]])
        break;

      ++f[a[j]];

      int len = j - i + 1;
      if (len > n / 2)
        break;

      if (mx[i][j] - mn[i][j] == j - i) {
        v[len].emplace_back(i, j, mn[i][j]);
      }
    }
    fill(f.begin(), f.end(), 0);
  }

  int ans = 0;
  bool poss = false;

  for (int l = n / 2; l >= 0 && !poss; --l) {
    for (int i = 0; i < v[l].size() && !poss; ++i) {
      for (int j = i + 1; j < v[l].size() && !poss; ++j) {
        auto [I1, J1, MIN1] = v[l][i];
        auto [I2, J2, MIN2] = v[l][j];

        if (I2 > J1 && abs(MIN1 - MIN2) == l) {
          ans = l;
          poss = true;
          break;
        }
      }
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
