#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> d1(2001), d2(2001);
    for (int i{}; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ++d1[x + y];
        ++d2[x - y + 1000];
    }

    ll ans{};
    for (auto f : d1) {
        ans += f * (f - 1) / 2;
    }

    for (auto f : d2) {
        ans += f * (f - 1) / 2;
    }

    cout << ans << '\n';
}
