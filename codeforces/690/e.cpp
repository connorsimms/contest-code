#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

constexpr ull MOD = 1e9 + 7;

ull exp(ull b, ull e) {
  ull res{1};
  b %= MOD;
  while (e) {
    if (e & 1)
      res = res * b % MOD;
    b = b * b % MOD;
    e >>= 1;
  }
  return res;
}

int main() {
  vector<ull> fac(200'001), inv(200'001);

  fac[0] = 1;
  for (ull i{1}; i < fac.size(); ++i) {
    fac[i] = fac[i - 1] * i % MOD;
  }

  inv.back() = exp(fac.back(), MOD - 2);
  for (ull i{inv.size() - 1}; i > 0; --i) {
    inv[i - 1] = inv[i] * i % MOD;
  }

  int t;
  cin >> t;
  while (t--) {
    ull ans{};
    ull n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (ull i{}; i < n; ++i)
      cin >> a[i];

    sort(begin(a), end(a));

    for (ull i{}; i < n; ++i) {
      auto it = upper_bound(begin(a) + i, end(a), a[i] + k);
      auto num = it - begin(a) - i - 1;

      if (m - 1 <= num) {
        ull ways = fac[num] * inv[m - 1] % MOD * inv[num - (m - 1)] % MOD;
        ans = (ans + ways) % MOD;
      }
    }

    cout << ans << '\n';
  }
}
