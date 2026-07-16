#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i{}; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans{};

    vector<int> Q1, Q2;
    for (int i{1}; i <= n; ++i) {
        if (adj[i].size() == 1) {
            Q1.push_back(i);
        }
    }

    auto q1 = &Q1;
    auto q2 = &Q2;

    while (!q1->empty()) {
        ++ans;

        for (auto x : *q1) {
            for (auto next : adj[x]) {
                erase(adj[next], x);
            }
        }

        for (auto x : *q1) {
            adj[x].clear();
        }

        for (int i{1}; i <= n; ++i) {
            if (adj[i].size() == 1)
                q2->push_back(i);
        }

        q1->clear();
        swap(q1, q2);
    }

    cout << ans << '\n';
}
