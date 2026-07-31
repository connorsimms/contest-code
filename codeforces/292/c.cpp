#include <bits/stdc++.h>
using namespace std;

// 135 -> [2 * 3] * [2 * 3 * 4 * 5 | 2 * 3 * 2 * 2 * 5] -> 531
// 1234 -> [2] * [2 * 3] * [2 * 3 * 4 | 2 * 3 * 2 * 2] -> 5x 2's and 2x 3's

int main() {
    vector<bool> isPrime(10, true);
    isPrime[0] = isPrime[1] = false;
    vector<vector<pair<int, int>>> pDiv(10);

    for (int i{2}; i < isPrime.size(); ++i) {
        if (!isPrime[i]) continue;
        pDiv[i].emplace_back(i, 1);
        for (int j = i * 2; j < isPrime.size(); j += i) {
            isPrime[j] = false;
            int x{j};
            int pow{};
            while (x && x % i == 0) {
                ++pow;
                x /= i;
            }
            pDiv[j].emplace_back(i, pow);
        }
    }

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> f(10);

    for (auto c : s) {
        for (int d = c - '0'; d >= 2; --d) {
            for (auto [p, mult] : pDiv[d]) {
                f[p] += mult;
            }
        }
    }

    for (int i{9}; i >= 2; --i) {
        if (!isPrime[i])
            continue;

        auto x = f[i];

        if (!x)
            continue;

        cout << string(x, '0' + i);

        for (int d = i; d >= 2; --d) {
            for (auto [p, mult] : pDiv[d]) {
                f[p] -= mult * x;
            }
        }
    }
    cout << '\n';
}
