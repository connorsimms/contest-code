#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> rem;
    for (int i{1}; i <= n; ++i)
        rem.insert(i);

    vector<int> ans(n + 1);
    for (int i = 0; i < m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;

        auto li = rem.lower_bound(l);
        auto ri = rem.upper_bound(r);

        for (auto it = li; it != ri; ++it) {
            auto id = *it;
            if (id != x)
                ans[id] = x;
        }

        rem.erase(li, ri);
        rem.insert(x);
    }

    for (int i{1}; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}
