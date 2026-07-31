#include <bits/stdc++.h>
using namespace std;

array<int, 4> dr = {-1, 1, 0, 0};
array<int, 4> dc = {0, 0, -1, 1};

void solve() {
    vector<string> g;
    int cr{};
    pair<int, int> start{-1, -1};
    string ln;

    while (getline(cin, ln) && ln.front() != '_') {
        g.push_back(ln);
        for (int c{}; c < ln.size(); ++c)
            if (ln[c] == '*')
                start = {cr, c};
        ++cr;
    }

    queue<pair<int, int>> q;
    q.push(start);
    g[start.first][start.second] = '#';

    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        for (int i{}; i < 4; ++i) {
            auto nr = f.first + dr[i];
            auto nc = f.second + dc[i];

            if (nr >= 0 && nr < g.size() && nc >= 0 && nc < g[nr].size() && g[nr][nc] == ' ') {
                g[nr][nc] = '#';
                q.emplace(nr, nc);
            }
        }
    }

    for (auto r : g)
        cout << r << '\n';
    if (ln.size() && ln.front() == '_') cout << ln << '\n';
}

int main() {
    int tc;
    cin >> tc;
    string jnk;
    getline(cin, jnk);
    while (tc--)
        solve();
}
