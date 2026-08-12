#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i{}; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    vector<int> cc(n + 1, -1);
    q.push(1);
    cc[1] = a[1];
    int ans{};

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        bool isLeaf = true;
        for (auto next : adj[cur]) {
            if (cc[next] == -1) {
                isLeaf = false;
                cc[next] = a[next] ? cc[cur] + 1 : 0;
                if (cc[next] <= m)
                    q.push(next);
            }
        }

        if (isLeaf && cc[cur] <= m)
            ++ans;
    }

    cout << ans << '\n';
}
