#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

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
  ull phi = 1e9 + 6;
  phi -= phi / 2;
  phi -= phi / (5e8 + 3);

  int n;
  cin >> n;

  ull num{1}, nummod{1}, sum{1}, prod{1};

  vector<pair<ull, ull>> pf;

  for (int i{}; i < n; ++i) {
    ull p, e;
    cin >> p >> e;
    pf.emplace_back(p, e);
    num = (num * (e + 1)) % MOD;
    sum = sum *
          (((exp(p, e + 1, MOD) + MOD - 1) % MOD) *
           (exp(p - 1, MOD - 2, MOD) % MOD) % MOD) %
          MOD;
    ull tot = e * (e + 1) / 2 % (MOD - 1);
    prod = exp(prod, e + 1, MOD) * exp(p, nummod * tot % (MOD - 1), MOD) % MOD;
    nummod = (nummod * (e + 1)) % (MOD - 1);
  }

  cout << num << " " << sum << " " << prod << '\n';
}
