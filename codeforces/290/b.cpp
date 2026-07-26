#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    array<int, 4> dr{-1, 1, 0, 0}, dc{0, 0, -1, 1};

    vector<vector<char>> g(n, vector<char>(m));
    for (int i{}; i < n; ++i) {
        for (int j{}; j < m; ++j) {
            cin >> g[i][j];
        }
    }

    vector<vector<bool>> seen(n, vector<bool>(m));

    auto dfs = [&](auto &&rec, int pr, int pc, int cr, int cc) {
        for (int i{}; i < 4; ++i) {
            auto nr = cr + dr[i], nc = cc + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (g[nr][nc] == g[cr][cc] && !(nr == pr && nc == pc)) {
                    if (seen[nr][nc])
                        return true;

                    seen[nr][nc] = true;

                    if (rec(rec, cr, cc, nr, nc))
                        return true;
                }
            }
        }
        return false;
    };

    for (int i{}; i < n; ++i) {
        for (int j{}; j < m; ++j) {
            if (!seen[i][j] && (seen[i][j] = true) && dfs(dfs, -1, -1, i, j)) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
}
