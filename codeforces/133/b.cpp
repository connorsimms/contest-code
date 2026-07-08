#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;

int main() {
    ull n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (ull i = 0; i < m; ++i) {
        ull a, b;
        cin >> a >> b;
        --a, --b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans{};

    vector<int> color(n);

    auto dfs = [&](int x, int c, auto &&rec) {
        color[x] = c;

        for (auto next : adj[x]) {
            if (color[next] == color[x]) {
                ++ans;
                return;
            }
        }

        for (auto next : adj[x]) {
            if (!color[next])
                rec(next, 3 - c, rec);
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!color[i])
            dfs(i, 1, dfs);
    }

    if ((n - ans) % 2 != 0)
        ++ans;

    cout << ans << '\n';
}
