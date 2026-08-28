#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

constexpr ull MOD = 1e9 + 7;

ull exp(ull b, ull e, ull mod) {
  b %= mod;
  ull res{1};
  while (e) {
    if (e & 1) {
      res = res * b % mod;
    }
    b = b * b % mod;
    e >>= 1;
  }
  return res;
}

int main() {
  vector<ull> fac(1'000'001), inv(1'000'001);
  fac[0] = inv[0] = 1;

  for (ull i{1}; i < fac.size(); ++i) {
    fac[i] = fac[i - 1] * i % MOD;
  }

  inv[inv.size() - 1] = exp(fac[inv.size() - 1], MOD - 2, MOD);
  for (ull i{fac.size() - 1}; i > 0; --i) {
    inv[i - 1] = inv[i] * i % MOD;
  }

  int n;
  cin >> n;
  for (int i{}; i < n; ++i) {
    ull a, b;
    cin >> a >> b;

    cout << fac[a] * inv[b] % MOD * inv[a - b] % MOD << '\n';
  }
}
