#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, d;
    cin >> n >> d;
    vector<pair<ll, ll>> f;
    for (int i{}; i < n; ++i) {
        int m, s;
        cin >> m >> s;
        f.emplace_back(m, s);
    }
    sort(begin(f), end(f));
    int l{}, r{1};
    ll ff{f.front().second};
    ll ans{ff};

    for (; l < n && r < n;) {
        auto [m1, s1] = f[l];
        auto [m2, s2] = f[r];

        if (m2 - m1 >= d) {
            ++l;
            ff -= s1;
        } else {
            ++r;
            ff += s2;
            ans = max(ans, ff);
        }
    }

    cout << ans << '\n';
}
