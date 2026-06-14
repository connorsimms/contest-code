#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <class T> using v = vector<T>;
template <class T, class U> void chmax(T &l, const U &r) { l = l < r ? r : l; }
template <class T, class U> void chmin(T &l, const U &r) { l = l > r ? r : l; }

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    v<int> ans(n + 1, k);
    v<int> isMex(n + 1, false);
    v<int> isMin(n + 1, false);
    v<pair<int, int>> mexQ, minQ;

    for (int i = 0; i < q; ++i) {
        int c, l, r;
        cin >> c >> l >> r;

        if (c == 1) {
            for (int j = l; j <= r; ++j) isMin[j] = true;
            minQ.emplace_back(l, r);
        } else {
            for (int j = l; j <= r; ++j) isMex[j] = true;
            mexQ.emplace_back(l, r);
        }
    }

    sort(mexQ.begin(), mexQ.end());

    for (int i = 1; i <= n; ++i) {
        if (isMex[i] && isMin[i]) ans[i] = k + 1;
    }

    for (auto [l, r] : mexQ) {
        int cnt = -1;
        for (int j = l; j <= r; ++j) {
            if (!isMin[j]) {
                if (ans[j] < k) {
                    cnt = ans[j];
                    continue;
                }

                ans[j] = (cnt + 1) % k;
                cnt = ans[j];
            }
        }
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
