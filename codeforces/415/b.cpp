#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, f;

    cin >> n >> f;

    vector<ll> gain(n);

    ll ans{};

    for (int i = 0; i < n; ++i) {
        ll k, l;
        cin >> k >> l;
        ans += min(k, l);
        gain[i] = min(2 * k, l) - min(k, l);
    }

    sort(gain.rbegin(), gain.rend());

    for (int i = 0; i < f; ++i) {
        ans += gain[i];
    }

    cout << ans << '\n';
}
