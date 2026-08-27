#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
constexpr ull MOD = 1e9 + 7;

ull exp(ull b, ull e, ull mod) {
  b %= mod;
  ull res{1};
  while (e) {
    if (e & 1) {
      res *= b;
      res %= mod;
    }
    b *= b;
    b %= mod;
    e >>= 1;
  }
  return res % mod;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ull a, b, c;
    cin >> a >> b >> c;

    if (!c) {
      cout << a << '\n';
      continue;
    }
    if (!b) {
      cout << 1 << '\n';
      continue;
    }
    if (!a) {
      cout << 0 << '\n';
      continue;
    }

    ull e = exp(b, c, MOD - 1);
    cout << exp(a, e, MOD) << '\n';
  }
}
