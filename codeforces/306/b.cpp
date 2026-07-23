#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<ll> c(n);
    for (int i{}; i < n; ++i)
        cin >> c[i];
    int ans{};
    for (int i{}; i < (1 << n); ++i) {
        if (__builtin_popcount(i) <= 1)
            continue;

        ll dif{};
        ll mnd = 1e6 + 1;
        ll mxd = 0;
        for (int j{}; j < n; ++j) {
            if (i & (1 << j)) {
                mnd = min(mnd, c[j]);
                mxd = max(mxd, c[j]);
                dif += c[j];
            }
        }

        if (dif >= l && dif <= r && mxd - mnd >= x) {
            ++ans;
        }
    }

    cout << ans << '\n';
}
