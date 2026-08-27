#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ull MOD = 998244353;

ull modexp(ull b, ull e, ull mod) {
  b %= mod;
  ull res{1};
  while (e) {
    if (e & 1) {
      res = (res * b) % mod;
    }
    b = (b * b) % mod;
    e >>= 1;
  }
  return res % mod;
}

int main() {
  ull n;
  cin >> n;

  vector<vector<int>> v(n);
  vector<int> f(1'000'001);

  for (ull i{}; i < n; ++i) {
    int k;
    cin >> k;

    for (int j{}; j < k; ++j) {
      int x;
      cin >> x;
      ++f[x];
      v[i].push_back(x);
    }
  }

  ull ans{};

  for (const auto &l : v) {
    for (auto i : l) {
      ull k = l.size();
      ans += f[i] * modexp(n * n % MOD * k % MOD, MOD - 2, MOD) % MOD;
      ans %= MOD;
    }
  }

  cout << ans << '\n';
}
