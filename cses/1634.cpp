#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = numeric_limits<ll>::max() / 2;

int main() {
  size_t n;
  cin >> n;

  ll x;
  cin >> x;

  vector<ll> c(n);
  for (size_t i{}; i < n; ++i) {
    cin >> c[i];
  }

  vector<ll> mem(x + 1, INF);
  mem[0] = 0;

  auto dp = [&](auto &&rec, ll amt) -> ll {
    if (mem[amt] != INF)
      return mem[amt];

    ll res{INF};
    for (auto d : c) {
      if (amt - d >= 0) {
        auto nxt = rec(rec, amt - d);
        if (nxt != -1)
          res = min(res, nxt + 1);
      }
    }

    if (res == INF)
      res = -1;

    return mem[amt] = res;
  };

  cout << dp(dp, x) << '\n';
}
