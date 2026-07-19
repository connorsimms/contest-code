#include <bits/stdc++.h>
using namespace std;

int main() {
    array<int, 4> dr = {-1, 1, 0, 0};
    array<int, 4> dc = {0, 0, -1, 1};

    int m, n;
    while (cin >> m >> n) {
        vector<vector<char>> g(m, vector<char>(n));
        vector<vector<bool>> seen(m, vector<bool>(n));

        for (int i{}; i < m; ++i) {
            for (int j{}; j < n; ++j) {
                cin >> g[i][j];
            }
        }

        int mr, mc;
        cin >> mr >> mc;
        char l = g[mr][mc];

        auto bfs = [&](int R, int C) -> int {
            queue<pair<int, int>> q;

            q.emplace(R, C);
            seen[R][C] = true;
            int num{1};

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                // cerr << "@ " << r << " " << c << "(" << num << ")" << endl;

                for (size_t i{}; i < 4; ++i) {
                    auto nr = r + dr[i];
                    auto nc = (c + dc[i] + n) % n;

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !seen[nr][nc] && g[nr][nc] == l) {
                        seen[nr][nc] = true;
                        ++num;
                        q.emplace(nr, nc);
                    }
                }
            }

            return num;
        };

        bfs(mr, mc);

        int ans{};

        for (int i{}; i < m; ++i) {
            for (int j{}; j < n; ++j) {
                if (!seen[i][j] && g[i][j] == l)
                    ans = max(ans, bfs(i, j));
            }
        }

        cout << ans << '\n';
    }
}
