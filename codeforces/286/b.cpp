#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i{}; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    int Q;
    cin >> Q;
    for (int i{}; i < Q; ++i) {
        int ans{};
        int u, v;
        cin >> u >> v;
        vector<bool> cseen(n + 1);
        for (auto [X, C] : adj[u]) {
            if (!cseen[C]) {
                cseen[C] = true;

                vector<int> seen(n + 1);
                queue<int> q;
                seen[u] = true;
                q.push(u);

                while (!q.empty()) {
                    auto f = q.front();
                    q.pop();
                    for (auto [next, c] : adj[f]) {
                        if (!seen[next]) {
                            if (c == C) {
                                seen[next] = true;
                                q.push(next);
                            }
                        }
                    }
                }

                if (seen[v]) {
                    ++ans;
                }
            }
        }

        cout << ans << '\n';
    }
}
