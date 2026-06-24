#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    ll ones = 0;
    ll twos = 0;
    ll slots = 0;
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 1)
            ++ones;
        else {
            ++twos;
            ans += x;
            slots += max(0, x / 2 - 1);
        }
    }

    int x = min(slots, ones);
    ans += x;
    ones -= x;

    if (twos == 1 && ones) ++ans;

    if (ans < 3)
        cout << 0 << '\n';
    else
        cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
