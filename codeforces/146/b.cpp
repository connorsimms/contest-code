#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1073741824;

int main() {
    vector<bool> isPrime(1'000'001, true);
    vector<vector<pair<int, int>>> pDivs(1'000'001);

    isPrime[0] = isPrime[1] = false;
    for (int i{2}; i < isPrime.size(); ++i) {
        if (!isPrime[i])
            continue;

        pDivs[i].emplace_back(i, 1);

        for (int j{i * 2}; j < isPrime.size(); j += i) {
            isPrime[j] = false;

            int m{};
            int k = j;
            while (k % i == 0) {
                k /= i;
                ++m;
            }

            pDivs[j].emplace_back(i, m);
        }
    }

    ll ans{};
    int a, b, c;
    cin >> a >> b >> c;
    for (int i{1}; i <= a; ++i) {
        for (int j{1}; j <= b; ++j) {
            for (int k{1}; k <= c; ++k) {
                ll d{1};
                // cerr << i * j * k << endl;
                for (auto [div, m] : pDivs[i * j * k]) {
                    d *= m + 1;
                    // cerr << "\t" << div << ", " << m << " d: " << d << endl;
                }
                ans += d;
                ans %= MOD;
            }
        }
    }
    cout << ans << '\n';
}
