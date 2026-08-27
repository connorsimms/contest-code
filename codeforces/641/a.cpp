#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull exp(ull b, ull e) {
  ull res{1};
  ull pow{b};
  while (e) {
    if (e & 1) {
      res *= pow;
    }
    e >>= 1;
    pow *= pow;
  }
  return res;
}

int main() {
  vector<bool> isPrime(500, true);
  vector<int> primes;
  isPrime[0] = isPrime[1] = false;
  for (size_t i{2}; i < isPrime.size(); ++i) {
    if (!isPrime[i])
      continue;
    primes.push_back(i);
    for (size_t j{i * i}; j < isPrime.size(); j += i) {
      isPrime[j] = false;
    }
  }

  map<int, map<int, int>> pm;

  int n;
  cin >> n;

  set<int> other;

  for (int i{}; i < n; ++i) {
    int x;
    cin >> x;

    for (int p : primes) {
      int cnt{};

      while (x % p == 0) {
        ++cnt;
        x /= p;
      }

      ++pm[p][cnt];
    }

    if (x != 1) {
      ++pm[x][1];
      other.insert(x);
    }
  }

  for (auto p : other) {
    auto freq = pm[p][1];
    pm[p][0] = n - freq;
  }

  ull ans{1};
  for (auto &[p, s] : pm) {
    auto it = begin(s);
    int mult = it->first;
    if (it->second <= 1) {
      ++it;
      mult = it->first;
    }
    ans *= exp(p, mult);
  }

  cout << ans << '\n';
}
