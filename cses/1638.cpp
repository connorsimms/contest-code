#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<vector<ll>> mem(n, vector<ll>(n));
  mem[n - 1][n - 1] = 1;

  string ln;
  getline(cin, ln);
  for (int i{}; i < n; ++i) {
    getline(cin, ln);
    for (int j{}; j < n; ++j) {
      if (ln[j] == '*')
        mem[i][j] = -1;
    }
  }

  auto dp = [&](auto &&rec, int r, int c) {
    if (mem[r][c])
      return mem[r][c];

    if (r + 1 < n) {
      auto x = rec(rec, r + 1, c);
      if (x != -1) {
        mem[r][c] += x;
        mem[r][c] %= MOD;
      }
    }

    if (c + 1 < n) {
      auto x = rec(rec, r, c + 1);
      if (x != -1) {
        mem[r][c] += x;
        mem[r][c] %= MOD;
      }
    }

    if (!mem[r][c])
      mem[r][c] = -1;

    return mem[r][c];
  };

  auto ans = dp(dp, 0, 0);
  if (ans == -1)
    cout << 0 << '\n';
  else
    cout << ans << '\n';
}
