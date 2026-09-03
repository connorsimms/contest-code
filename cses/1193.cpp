#include <bits/stdc++.h>
using namespace std;

constexpr array<int, 4> dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
constexpr string itom = "UDLR";

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<char>> g(n, vector<char>(m));

  vector<vector<bool>> seen(n, vector<bool>(m));

  vector<vector<int>> move(n, vector<int>(m, -1));

  vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m));

  int sr{}, sc{}, er{}, ec{};

  for (int i{}; i < n; ++i) {
    for (int j{}; j < m; ++j) {
      cin >> g[i][j];
      if (g[i][j] == 'A')
        sr = i, sc = j;
      if (g[i][j] == 'B')
        er = i, ec = j;
    }
  }

  queue<pair<int, int>> q;
  q.emplace(sr, sc);
  seen[sr][sc] = true;

  while (!q.empty()) {
    auto f = q.front();
    auto [r, c] = f;
    q.pop();

    for (int i{}; i < 4; ++i) {
      auto nr = r + dr[i];
      auto nc = c + dc[i];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m && !seen[nr][nc] &&
          g[nr][nc] != '#') {
        seen[nr][nc] = true;
        move[nr][nc] = i;
        par[nr][nc] = f;
        q.emplace(nr, nc);
      }
    }
  }

  if (seen[er][ec]) {
    cout << "YES\n";

    deque<char> ans;
    int cr = er, cc = ec;

    while (true) {
      if (cr == sr && cc == sc)
        break;

      ans.push_front(itom[move[cr][cc]]);

      auto tr = cr, tc = cc;

      cr = par[tr][tc].first;
      cc = par[tr][tc].second;
    }

    cout << ans.size() << '\n';
    bool first = true;
    for (auto x : ans) {
      if (!first)
        cout << ' ';
      cout << x;
    }
    cout << '\n';
  } else {
    cout << "NO\n";
  }
}
