#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    ll tot{1};
    ll cmp{1};

    for (int i{}; i < n; ++i) {
        tot *= 27;
        cmp *= 7;
        tot %= MOD;
        cmp %= MOD;
    }

    ll ans = (tot - cmp + MOD) % MOD;
    cout << ans << '\n';
}
