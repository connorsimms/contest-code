#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

vector<bool> isPrime(20000001, true);
vector<ull> p;
vector<pair<ull, ull>> tp;

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (ull i{2}; i < isPrime.size(); ++i) {
        if (!isPrime[i]) continue;

        for (ull j{i * i}; j < isPrime.size(); j += i) {
            isPrime[j] = false;
        }
        if (!p.empty() && p.back() == i - 2) {
            tp.emplace_back(p.back(), i);
        }
        p.push_back(i);
    }
}

int main() {
    sieve();

    int q;
    while (cin >> q) {
        --q;
        ull a, b;
        tie(a, b) = tp[q];
        cout << "(" << a << ", " << b << ")\n";
    }
}
