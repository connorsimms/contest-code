#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
  vector<bool> isPrime(1001, true);
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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    ull ans{1};

    for (auto p : primes) {
      if (p * p > n)
        break;

      if (n % p == 0) {
        int cnt{};
        while (n % p == 0) {
          ++cnt;
          n /= p;
        }
        ans *= cnt + 1;
      }
    }

    if (n != 1)
      ans *= 2;

    cout << ans << '\n';
  }
}
