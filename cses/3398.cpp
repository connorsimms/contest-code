#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
constexpr ull MOD = 1e9 + 7;

ull exp(ull b, ull e) {
  ull res{1};
  ull pow{b};
  while (e) {
    if (e & 1) {
      res *= pow;
      res %= MOD;
    }
    pow *= pow;
    pow %= MOD;
    e >>= 1;
  }
  return res;
}

int main() {
  vector<bool> isPrime(1'000, true);
  isPrime[0] = isPrime[1] = false;
  vector<int> primes;

  for (size_t i{2}; i < isPrime.size(); ++i) {
    if (!isPrime[i])
      continue;

    primes.push_back(i);

    for (size_t j{i * i}; j < isPrime.size(); j += i) {
      isPrime[j] = false;
    }
  }

  int n;
  cin >> n;
  vector<int> p(n);

  for (int i{}; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }

  set<int> lens;

  vector<bool> seen(n);
  for (int i{}; i < n; ++i) {
    if (seen[i])
      continue;

    int len{1};
    queue<int> q;
    q.push(i);
    seen[i] = true;

    while (!q.empty()) {
      auto f = q.front();
      q.pop();

      if (!seen[p[f]]) {
        seen[p[f]] = true;
        q.push(p[f]);
        ++len;
      }
    }

    lens.insert(len);
  }

  map<int, int> pf;

  for (auto l : lens) {
    for (auto pr : primes) {
      if (pr * pr > l)
        break;

      if (l % pr == 0) {
        int cnt{};
        while (l % pr == 0) {
          ++cnt;
          l /= pr;
        }

        pf[pr] = max(pf[pr], cnt);
      }
    }

    if (l != 1) {
      pf[l] = max(pf[l], 1);
    }
  }

  ull ans{1};
  for (auto [pr, f] : pf) {
    ans *= exp(pr, f);
    ans %= MOD;
  }

  cout << ans % 1'000'000'007 << '\n';
}
