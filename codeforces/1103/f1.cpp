#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

vector<bool> isPrime(500'001, true);
vector<vector<pair<int, int>>> divisors(500'001);

constexpr ll MOD = 1e9 + 7;

void sieve() {
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i < isPrime.size(); ++i) {
    if (!isPrime[i])
      continue;

    divisors[i].emplace_back(i, 1);

    for (int j = i * 2; j < isPrime.size(); j += i) {
      int mult = 0;
      for (int k = j; k && k % i == 0; k /= i)
        ++mult;
      divisors[j].emplace_back(i, mult);
      isPrime[j] = false;
    }
  }
}

void solve() {
  int n, x;
  cin >> n >> x;

  vector<int> p(n);

  unordered_map<int, int> count;
  set<int> divs;

  for (int i = 0; i < n; ++i) {
    cin >> p[i];

    for (auto [d, m] : divisors[p[i]]) {
      count[d] += m;
      divs.insert(d);
    }
  }

  ll ans = 1;

  for (auto d : divs) {
    ans *= count[d] + 1;
    ans %= MOD;
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  sieve();

  int t;
  cin >> t;
  while (t--)
    solve();
}
