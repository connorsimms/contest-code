#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

ll exp(ll b, ll e) {
  ll res{1};
  b %= MOD;

  while (e) {
    if (e & 1)
      res = res * b % MOD;
    b = b * b % MOD;
    e >>= 1;
  }
  return res;
}

ll inv(ll x) { return exp(x, MOD - 2); }

int main() {
  string a;
  cin >> a;

  vector<ll> fac(1'000'000), invfac(1'000'000);
  fac[0] = 1;
  for (size_t i{1}; i < fac.size(); ++i)
    fac[i] = fac[i - 1] * i % MOD;

  invfac.back() = inv(fac.back());
  for (size_t i = invfac.size() - 1; i > 0; --i)
    invfac[i - 1] = invfac[i] * i % MOD;

  vector<vector<ll>> mem(a.size(), vector<ll>(a.size()));

  for (size_t i{}; i < a.size(); ++i) {
    mem[i][i] = -1;

    if (i < a.size() - 1) {
      if (a[i] == a[i + 1])
        mem[i][i + 1] = 1;
      else
        mem[i][i + 1] = -1;
    }
  }

  auto dp = [&](auto &&rec, int l, int r) -> ll {
    if (mem[l][r])
      return mem[l][r];

    if (a[l] == a[l + 1]) {
      if (l + 2 <= r) {
        auto w = rec(rec, l + 2, r);
        if (w != -1) {
          auto lop = 1;
          auto rop = (r - (l + 2) + 1) / 2;

          auto ways = fac[lop + rop];
          ways = ways * invfac[lop] % MOD;
          ways = ways * invfac[rop] % MOD;
          ways = ways * w % MOD;

          mem[l][r] += ways;
          mem[l][r] %= MOD;
        }
      }
    }

    for (int i{l + 2}; i <= r; ++i) {
      if (a[i] == a[l]) {
        auto lw = (l + 1 <= i - 1) ? rec(rec, l + 1, i - 1) : 1LL;
        if (lw == -1)
          lw = 0;

        auto rw = (i + 1 <= r) ? rec(rec, i + 1, r) : 1LL;
        if (rw == -1)
          rw = 0;

        if (lw && rw) {
          auto lop = 1 + ((i - 1) - (l + 1) + 1) / 2;
          auto rop = (r - (i + 1) + 1) / 2;

          auto ways = fac[lop + rop];
          ways = ways * invfac[lop] % MOD;
          ways = ways * invfac[rop] % MOD;
          ways = ways * (lw * rw % MOD) % MOD;

          mem[l][r] += ways;
          mem[l][r] %= MOD;
        }
      }
    }

    if (!mem[l][r])
      return mem[l][r] = -1;

    return mem[l][r];
  };

  auto ans = dp(dp, 0, a.size() - 1);
  if (ans == -1)
    ans = 0;

  cout << ans << '\n';
}
