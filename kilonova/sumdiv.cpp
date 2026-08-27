#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
constexpr ull MOD = 1e9 + 7;

ull exp(ull b, ull e, ull mod) {
  ull res{1};
  b %= mod;
  while (e) {
    if (e & 1)
      res = res * b % mod;
    b = b * b % mod;
    e >>= 1;
  }
  return res;
}

int main() {
  ifstream fin("sumdiv.in");
  ofstream fout("sumdiv.out");

  ull a, b;
  fin >> a >> b;
  ull ans{1};

  for (ull p{2}; p * p <= a; ++p) {
    if (a % p == 0) {
      ull cnt{};

      while (a % p == 0) {
        ++cnt;
        a /= p;
      }

      if (p % MOD == 1) {
        ans = ans * ((((b % MOD) * (cnt % MOD)) % MOD + 1) % MOD) % MOD;
        continue;
      }

      cnt *= b % (MOD - 1);
      cnt %= MOD - 1;

      // (p^{k+1} - 1) / (p - 1)
      ans = ans *
            ((exp(p, (cnt + 1) % (MOD - 1), MOD) + MOD - 1) % MOD *
             exp(p - 1, MOD - 2, MOD) % MOD) %
            MOD;
    }
  }

  if (a != 1) {
    if (a % MOD == 1) {
      ans = (ans * ((b % MOD) + 1 % MOD)) % MOD;
    } else {
      ull cnt = b % (MOD - 1);
      ans = ans *
            ((exp(a, (cnt + 1) % (MOD - 1), MOD) + MOD - 1) % MOD *
             exp(a - 1, MOD - 2, MOD) % MOD) %
            MOD;
    }
  }

  fout << ans << '\n';
}
