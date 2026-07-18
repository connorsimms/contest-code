#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 mt{static_cast<mt19937::result_type>(
    chrono::steady_clock::now().time_since_epoch().count())};

using uid = uniform_int_distribution<ll>;

void gen() {
    uid N{1, 10}, X{1, 100}, H{1, 100};

    set<int> xs;

    auto n = N(mt);

    cout << n << '\n';

    while (xs.size() < n) {
        auto x = X(mt);
        xs.insert(x);
    }

    for (auto x : xs) {
        cout << x << ' ' << H(mt) << '\n';
    }
}

void brute() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> t;

    for (int i{}; i < n; ++i) {
        ll x, h;
        cin >> x >> h;
        t.emplace_back(x, h);
    }

    int ans{};
    for (int m1{}; m1 < (1 << n); ++m1) {
        for (int m2{}; m2 < (1 << n); ++m2) {
            bool valid = true;
            for (int i{}; i < n && valid; ++i) {
                if (!(m1 & (1 << i))) continue;

                if (m2 & (1 << i) && i > 0) {
                    auto [x1, h1] = t[i - 1];
                    auto [x2, h2] = t[i];

                    if ((m1 & (1 << (i - 1))) && !(m2 & (1 << (i - 1))) && x2 - h2 <= x1 + h1) {
                        valid = false;
                    }

                    if (x2 - h2 <= x1) {
                        valid = false;
                    }
                }

                if (!(m2 & (1 << i)) && i < n - 1) {
                    auto [x1, h1] = t[i];
                    auto [x2, h2] = t[i + 1];

                    if ((m1 & (1 << (i + 1))) && (m2 & (1 << (i + 1))) && x2 - h2 <= x1 + h1) {
                        valid = false;
                    }

                    if (x1 + h1 >= x2) {
                        valid = false;
                    }
                }
            }
            if (valid) ans = max(ans, __builtin_popcount(m1));
        }
    }

    cout << ans << '\n';
}

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> t;

    for (int i{}; i < n; ++i) {
        ll x, h;
        cin >> x >> h;
        t.emplace_back(x, h);
    }

    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    vector<vector<int>> dp(3, vector<int>(n));

    dp[1][0] = 1;

    for (int i = 1; i < n; ++i) {
        if (i == n - 1) {
            dp[2][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1])) + 1;
            break;
        }

        dp[0][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));

        auto [x1, h1] = t[i - 1];
        auto [x2, h2] = t[i];
        auto [x3, h3] = t[i + 1];

        if (x2 + h2 < x3) {
            dp[2][i] = dp[0][i] + 1;
        }

        if (x1 < x2 - h2) {
            dp[1][i] = max(dp[1][i], max(dp[0][i - 1], dp[1][i - 1]) + 1);
        }

        if (x1 + h1 < x2 - h2) {
            dp[1][i] = max(dp[1][i], dp[2][i - 1] + 1);
        }
    }

    // for (auto r : dp) {
    //     for (auto c : r) {
    //         cerr << c << ' ';
    //     }
    //     cerr << '\n';
    // }

    cout << max(dp[0].back(), max(dp[1].back(), dp[2].back())) << '\n';
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        auto mode = string(argv[1]);
        if (mode == "gen") {
            gen();
        }
        if (mode == "brute") {
            brute();
        }
    } else {
        solve();
    }
}
