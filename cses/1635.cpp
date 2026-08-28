#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll MOD = 1e9 + 7;

int main() {
  ll n, x;
  cin >> n >> x;

  vector<ll> c(n);
  for (int i{}; i < n; ++i)
    cin >> c[i];

  sort(c.begin(), c.end());

  vector<ll> mem(x + 1);

  auto dp = [&](auto &&rec, ll amt) {
    if (mem[amt])
      return mem[amt];

    bool is_coin = false;

    for (auto d : c) {
      if (d > amt)
        break;

      is_coin |= amt == d;

      auto nxt = rec(rec, amt - d);
      if (nxt != -1) {
        mem[amt] += rec(rec, amt - d);
        mem[amt] %= MOD;
      }
    }

    if (is_coin) {
      mem[amt] += 1;
      mem[amt] %= MOD;
    }

    if (!mem[amt])
      mem[amt] = -1;

    return mem[amt];
  };

  auto ans = dp(dp, x);
  if (ans == -1)
    cout << 0 << '\n';
  else
    cout << ans << '\n';
}
