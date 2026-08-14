#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ull n;
    cin >> n;

    if (n <= 2) {
        cout << -1 << '\n';
        return 0;
    }

    vector<bool> isPrime(1'000'000, true);
    isPrime[0] = isPrime[1] = false;

    for (ull i{2}; i < isPrime.size(); ++i) {
        if (!isPrime[i])
            continue;

        for (ull j{i * i}; j < isPrime.size(); j += i) {
            isPrime[j] = false;
        }
    }

    vector<ull> pdiv;

    ull cp{n};
    for (ull i{2}; i < isPrime.size(); ++i) {
        if (!isPrime[i])
            continue;

        if (cp % i == 0) {
            pdiv.push_back(i);
            while (cp % i == 0)
                cp /= i;
        }
    }
    if (cp != 1)
        pdiv.push_back(cp);

    if (pdiv.empty()) {
        ull prod = n * n;
        ull x = prod / 2;
        cout << x << ' ' << x + 1 << '\n';
        return 0;
    }

    if (pdiv.size() == 1 && pdiv.front() == 2) {
        cout << 3 * (n / 4) << ' ' << 5 * (n / 4) << '\n';
        return 0;
    }

    ull p = pdiv[0] == 2 ? pdiv[1] : pdiv[0];
    ull prod = p * p;
    ull x = prod / 2;
    ull y = n / p;

    cout << y * x << ' ' << y * (x + 1) << '\n';
}
