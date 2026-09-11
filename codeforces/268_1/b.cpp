#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, q, l, r;
    cin >> p >> q >> l >> r;

    vector<pair<int, int>> Z;
    for (int i{}; i < p; ++i) {
        int a, b;
        cin >> a >> b;
        Z.emplace_back(a, b);
    }

    vector<pair<int, int>> X;
    for (int i{}; i < q; ++i) {
        int c, d;
        cin >> c >> d;
        X.emplace_back(c, d);
    }

    int ans{};
    for (int t{l}; t <= r; ++t) {
        int i{}, j{};
        while (i < p && j < q) {
            auto [a, b] = Z[i];
            auto [c, d] = X[j];
            c += t;
            d += t;

            if (b >= c && a <= d) {
                ++ans;
                break;
            }

            if (a > d)
                ++j;

            if (c > b)
                ++i;
        }
    }

    cout << ans << '\n';
}
