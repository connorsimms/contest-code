#include <bits/stdc++.h>
using namespace std;

array<int, 4> dr{-1, 1, 0, 0}, dc{0, 0, -1, 1};

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i{}; i < n; ++i) {
            string row;
            cin >> row;
            for (int j{}; j < m; ++j) {
                if (row[j] == '1') {
                    dist[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        while (!q.empty()) {
            int r, c;
            auto f = q.front();
            tie(r, c) = f;
            q.pop();

            for (int i{}; i < 4; ++i) {
                auto nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if (dist[nr][nc] == -1) {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.emplace(nr, nc);
                    }
                }
            }
        }

        for (const auto &r : dist) {
            bool first = true;
            for (auto c : r) {
                if (!first)
                    cout << ' ';
                cout << c, first = false;
            }
            cout << '\n';
        }
    }
}
