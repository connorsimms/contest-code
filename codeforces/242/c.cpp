#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 1 mod 1  1 mod 2
// 2 mod 1  2 mod 2
// 3 mod 1  3 mod 2
// 4 mod 1  4 mod 2
int main() {
    int n;
    cin >> n;

    vector<int> pfx(1e6 + 1);
    for (int i{1}; i < pfx.size(); ++i) {
        pfx[i] = pfx[i - 1] ^ i;
    }

    ll ans{};
    for (int i{1}; i <= n; ++i) {
        ll x;
        cin >> x;
        ans ^= x;

        auto div = n / i;
        auto rem = n % i;

        if (div & 1) {
            ans ^= pfx[i - 1];
        }

        ans ^= pfx[rem];
    }

    cout << ans << '\n';
}
