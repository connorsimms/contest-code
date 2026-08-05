#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);

    while (b) {
        auto tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ll N, T;
    while (cin >> N >> T) {
        vector<ll> c(N);

        for (int i{}; i < N; ++i) {
            cin >> c[i];
        }

        for (int t{}; t < T; ++t) {
            ll h;
            cin >> h;
            ll ans_lo{}, ans_hi{numeric_limits<ll>::max()};
            for (int i{}; i < N; ++i) {
                for (int j{i + 1}; j < N; ++j) {
                    for (int k{j + 1}; k < N; ++k) {
                        for (int l{k + 1}; l < N; ++l) {
                            auto mult = lcm(c[i], lcm(c[j], lcm(c[k], c[l])));
                            auto lo = (h / mult);
                            auto hi = (h / mult) + (h % mult != 0);
                            ans_lo = max(ans_lo, lo * mult);
                            ans_hi = min(ans_hi, hi * mult);
                        }
                    }
                }
            }
            cout << ans_lo << ' ' << ans_hi << '\n';
        }
    }
}
