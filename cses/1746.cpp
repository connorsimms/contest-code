#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> x(n);
  for (int i{}; i < n; ++i)
    cin >> x[i];

  vector<vector<ll>> mem(m + 1, vector<ll>(n));

  if (x[0]) {
    mem[x[0]][0] = 1;
  } else {
    for (int i{1}; i <= m; ++i)
      mem[i][0] = 1;
  }

  // mem[i + dv][j + 1] += mem[i][j];
  for (int i{}; i < n - 1; ++i) {
    for (int j{1}; j <= m; ++j) {
      for (auto dv : {-1, 0, 1}) {
        if (j + dv >= 1 && j + dv <= m) {
          if (x[i + 1] && x[i + 1] != j + dv)
            continue;

          mem[j + dv][i + 1] += mem[j][i];
          mem[j + dv][i + 1] %= MOD;
        }
      }
    }
  }

  ll ans{};
  for (int j{1}; j <= m; ++j) {
    ans += mem[j][n - 1];
    ans %= MOD;
  }

  cout << ans << '\n';
}
