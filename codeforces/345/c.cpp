#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    map<pair<int, int>, ll> fp;
    map<int, ll> fx, fy;
    int dup{};
    for (int i{}; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        ++fp[{x, y}];
        ++fx[x];
        ++fy[y];
    }

    ll ans{};

    for (auto [x, f] : fx) {
        ans += f * (f - 1) / 2;
    }

    for (auto [y, f] : fy) {
        ans += f * (f - 1) / 2;
    }

    for (auto [p, f] : fp) {
        ans -= f * (f - 1) / 2;
    }

    cout << ans - dup << '\n';
}
