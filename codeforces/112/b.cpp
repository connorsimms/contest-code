#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    long long n, k;
    cin >> n >> k;

    ll l{}, r{n};

    ll ans{};

    while (l <= r) {
        auto m = (l + r) / 2;

        ll lines{};

        while (m) {
            lines += m;
            m /= k;
        }

        m = (l + r) / 2;

        if (lines >= n) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans << '\n';
}
