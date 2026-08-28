#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<ll> mem(n + 1, 0);

  auto dp = [&](auto &&rec, int x) -> ll {
    if (mem[x])
      return mem[x];

    ll res = (1 <= x && x <= 6) ? 1 : 0;

    for (int i{1}; i <= min(x, 6); ++i) {
      res += rec(rec, x - i);
      res %= MOD;
    }

    return mem[x] = res;
  };

  cout << dp(dp, n) << '\n';
}
