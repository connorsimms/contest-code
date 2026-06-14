#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <class T> using v = vector<T>;
template <class T, class U> void chmax(T &l, const U &r) { l = l < r ? r : l; }
template <class T, class U> void chmin(T &l, const U &r) { l = l > r ? r : l; }

void solve() {
    int n;
    cin >> n;
    v<int> a(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++a[x];
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (a[i]) {
            if (a[i] >= i)
                ans += a[i] - i;
            else
                ans += a[i];
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
