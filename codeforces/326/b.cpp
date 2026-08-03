#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

vector<ull> primes;
vector<bool> isPrime(1'000'001, true);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (ull i{2}; i < isPrime.size(); ++i) {
        if (!isPrime[i]) continue;
        for (ull j{i * i}; j < isPrime.size(); j += i) {
            isPrime[j] = false;
        }
        primes.push_back(i);
    }
}

int main() {
    ull n;
    cin >> n;
    sieve();

    ull ans{1};

    for (auto p : primes) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            ans *= p;
        }
    }

    if (n != 1)
        ans *= n;

    cout << ans << '\n';
}
