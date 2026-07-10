#include <bits/stdc++.h>
using namespace std;

consteval array<bool, 100> sieve() {
    array<bool, 100> isPrime{};
    fill(isPrime.begin(), isPrime.end(), true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < 100; ++i) {
        if (!isPrime[i])
            continue;

        for (int j = i * i; j < 100; j += i)
            isPrime[j] = false;
    }

    return isPrime;
}

constexpr array<bool, 100> isPrime = sieve();

int main() {
    int n, m;
    cin >> n >> m;

    if (isPrime[n] && isPrime[m]) {
        bool adj = true;
        for (int i = n + 1; i < m; ++i) {
            if (isPrime[i])
                adj = false;
        }

        if (adj)
            cout << "YES\n";
        else
            cout << "NO\n";
    } else {
        cout << "NO\n";
    }
}
