#include <bits/stdc++.h>
using namespace std;

constexpr array<int, 8> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
constexpr array<int, 8> dc = {-1, 0, 1, -1, 1, -1, 0, 1};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int qr{}, qc{};

    vector<string> b(n);
    for (int r{}; r < n; ++r) {
        cin >> b[r];
        for (int c{}; c < m; ++c) {
            if (b[r][c] == 'S')
                qr = r, qc = c;
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    int ans = -1;
    q.emplace(qr, qc);
    dist[qr][qc] = 0;
    bool found = false;

    while (!found && !q.empty()) {
        int r, c;
        auto f = q.front();
        q.pop();
        tie(r, c) = f;

        for (int i{}; !found && i < 8; ++i) {
            for (int mag{1}; !found; ++mag) {
                auto nr = r + dr[i] * mag;
                auto nc = c + dc[i] * mag;
                if (nr < 0 || nr >= n || nc < 0 || nc >= m || b[nr][nc] == 'X')
                    break;

                if (dist[nr][nc] != -1) {
                    if (dist[nr][nc] <= dist[r][c]) break;
                    else continue;
                }

                dist[nr][nc] = dist[r][c] + 1;

                if (b[nr][nc] == 'F') {
                    ans = dist[nr][nc];
                    found = true;
                }

                q.emplace(nr, nc);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}
