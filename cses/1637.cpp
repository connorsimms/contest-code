#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e9;

int main() {
  ll n;
  cin >> n;
  vector<ll> mem(n + 1, INF);
  mem[0] = 0;

  auto dp = [&](auto &&rec, ll amt) -> ll {
    if (mem[amt] != INF)
      return mem[amt];

    auto x = amt;
    while (x) {
      auto d = x % 10;
      if (d) {
        mem[amt] = min(mem[amt], rec(rec, amt - d) + 1);
      }
      x /= 10;
    }

    return mem[amt];
  };

  cout << dp(dp, n) << '\n';
}
