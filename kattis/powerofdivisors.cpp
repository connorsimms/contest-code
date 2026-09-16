#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

vector<ull> primes;
vector<bool> isPrime(1'000'000, true);
vector<vector<pair<ull, ull>>> pf(1'000'000);

ull sqrt(ull x) {
  ull lo = 1;
  ull hi = 1e9;

  while (lo <= hi) {
    auto m = (lo + hi) / 2;

    if (m * m < x) {
      lo = m + 1;
    } else if (m * m > x) {
      hi = m - 1;
    } else {
      return m;
    }
  }

  return 0;
}

void sieve() {
  isPrime[0] = isPrime[1] = false;
  for (size_t i{2}; i < isPrime.size(); ++i) {
    if (!isPrime[i])
      continue;

    primes.push_back(i);

    for (size_t j{i}; j < isPrime.size(); j += i) {
      isPrime[j] = false;

      ull mult{};

      auto x = j;
      while (x % i == 0) {
        x /= i;
        ++mult;
      }

      pf[j].emplace_back(i, mult);
    }
  }
}

pair<ull, bool> binexp(ull b, ull e) {
  ull res{1};
  ull lim = numeric_limits<ull>::max();

  while (e) {
    if (e & 1) {

      // res * b > lim
      // res * b > (lim / b) * b + (lim % b)
      // (res - lim / b) * b > lim % b
      if (res >= lim / b) {
        if ((res - lim / b) * b > lim % b) {
          return {0, true};
        }
      }

      res *= b;
    }

    if ((e >> 1) && b >= lim / b) {
      if ((b - lim / b) * b > lim % b) {
        return {0, true};
      }
    }

    b *= b;
    e >>= 1;
  }

  return {res, false};
}

bool test(ull i, ull x) {
  ull numFac = 1;

  for (auto [p, mult] : pf[i]) {
    numFac *= mult + 1;
  }

  auto [res, over] = binexp(i, numFac);

  if (over)
    return false;

  return res == x;
}

int main() {
  sieve();

  ull x;
  cin >> x;

  for (ull i{1}; i < 1'000'000; ++i) {
    if (test(i, x)) {
      cout << i << '\n';
      return 0;
    }
  }

  bool isprm = true;
  ull rt = sqrt(x);

  for (auto p : primes) {
    if (rt % p == 0)
      isprm = false;
  }

  if (isprm) {
    cout << rt << '\n';
    return 0;
  }

  cout << -1 << '\n';
  return 0;
}
