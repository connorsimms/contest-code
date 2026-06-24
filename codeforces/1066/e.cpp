#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <class T> using v = vector<T>;
template <class T, class U> void chmax(T &l, const U &r) { l = l < r ? r : l; }
template <class T, class U> void chmin(T &l, const U &r) { l = l > r ? r : l; }

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a;
    vector<int> f(400'001);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (!f[x]) a.push_back(x);

        ++f[x];
    }

    sort(a.begin(), a.end());

    ll ans = 0;
    ll cur = 0;
    ll surplus = max(0, f[a[0]] - k);

    for (int i = 1; i < a.size(); ++i) {
        int dist = a[i] - a[i - 1];

        if (dist > surplus) {
            cur += surplus;
            ans = max(ans, cur);
            cur = 0;
            surplus = 0;
        } else {
            cur += min<ll>(surplus, dist);
            surplus = max<ll>(0, surplus - dist + 1);
        }

        if (surplus) {
            surplus += max<ll>(0, f[a[i]] - 1);
        } else {
            surplus = max(0, f[a[i]] - k);
        }
    }

    cur += surplus;
    ans = max(ans, cur);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
