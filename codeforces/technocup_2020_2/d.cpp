#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  vector<int> primes;
  vector<bool> isPrime(10'001, true);

  isPrime[0] = isPrime[1] = false;
  for (size_t i{2}; i < isPrime.size(); ++i) {
    if (!isPrime[i])
      continue;

    primes.push_back(i);

    for (size_t j{i}; j < isPrime.size(); j += i) {
      isPrime[j] = false;
    }
  }

  int n, k;
  cin >> n >> k;

  vector<vector<pair<int, int>>> factors(n);
  map<vector<pair<int, int>>, ll> fmap;
  vector<int> a(n);

  for (int i{}; i < n; ++i) {
    cin >> a[i];
    auto x = a[i];

    for (auto p : primes) {
      if (x % p == 0) {
        ll cnt{};
        while (x % p == 0) {
          x /= p;
          ++cnt;
        }

        cnt %= k;
        if (cnt)
          factors[i].emplace_back(p, cnt);
      }
    }

    if (x != 1)
      factors[i].emplace_back(x, 1);

    ++fmap[factors[i]];
  }

  ll ans{};
  for (auto [f, cnt] : fmap) {
    vector<pair<int, int>> comp;
    for (auto [p, e] : f) {
      if (k - e)
        comp.emplace_back(p, k - e);
    }

    ans += cnt * fmap[comp];
    if (comp == f)
      ans -= cnt;
  }

  ans /= 2;

  cout << ans << '\n';
}
