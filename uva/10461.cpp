#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int r, int v, const vector<vector<int>> &dep, const vector<ll> &t, vector<ll> &asum, vector<ll> &csum, vector<bool> &visited) {
    for (auto n : dep[v]) {
        if (visited[n]) continue;
        visited[n] = true;
        csum[r] += t[n];
        asum[n] += t[r];
        dfs(r, n, dep, t, asum, csum, visited);
    }
}

int main() {
    int v, e, tc{1};

    while (cin >> v >> e && !(v == 0 && e == 0)) {
        cout << "Case #" << tc++ << ":\n";

        vector<ll> t(v + 1);

        ll tot{};

        for (int i{1}; i <= v; ++i) {
            cin >> t[i];
            tot += t[i];
        }

        vector<vector<int>> dep(v + 1);
        vector<int> inc(v + 1);

        for (int i{}; i < e; ++i) {
            int a, b;
            cin >> a >> b;
            ++inc[b];
            dep[a].push_back(b);
        }

        vector<ll> asum(v + 1), csum(v + 1);

        for (int i{1}; i <= v; ++i) {
            vector<bool> visited(v + 1);
            visited[i] = true;
            dfs(i, i, dep, t, asum, csum, visited);
        }

        int q;
        cin >> q;
        for (int i{}; i < q; ++i) {
            int x;
            cin >> x;
            cout << tot - asum[x] - csum[x] - t[x] << '\n';
        }

        cout << '\n';
    }
}
