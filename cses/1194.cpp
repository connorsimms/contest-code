#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

constexpr array<int, 4> dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
constexpr string dir = "UDLR";

int main() {
  int n, m;
  cin >> n >> m;

  queue<pair<int, int>> q, mq;
  vector<vector<int>> d(n, vector<int>(m, INF)), md(n, vector<int>(m, INF));
  vector<vector<int>> move(n, vector<int>(m, -1)), mmove(n, vector<int>(m, -1));
  vector<vector<char>> g(n, vector<char>(m));
  bool edge = false;
  for (size_t i{}; i < n; ++i) {
    for (size_t j{}; j < m; ++j) {
      cin >> g[i][j];

      if (g[i][j] == 'A') {
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
          edge = true;
        }
        q.emplace(i, j);
        d[i][j] = 0;
      }

      if (g[i][j] == 'M') {
        mq.emplace(i, j);
        md[i][j] = 0;
      }
    }
  }

  if (edge) {
    cout << "YES\n0\n";
    return 0;
  }

  while (!q.empty()) {
    auto f = q.front();
    q.pop();
    auto [r, c] = f;

    for (size_t i{}; i < 4; ++i) {
      auto nr = r + dr[i], nc = c + dc[i];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
        if (d[nr][nc] != INF || g[nr][nc] != '.')
          continue;

        d[nr][nc] = d[r][c] + 1;
        q.emplace(nr, nc);
        move[nr][nc] = i;
      }
    }
  }

  while (!mq.empty()) {
    auto f = mq.front();
    mq.pop();
    auto [r, c] = f;

    for (size_t i{}; i < 4; ++i) {
      auto nr = r + dr[i], nc = c + dc[i];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
        if (md[nr][nc] != INF || g[nr][nc] != '.')
          continue;

        md[nr][nc] = md[r][c] + 1;
        mq.emplace(nr, nc);
        mmove[nr][nc] = i;
      }
    }
  }

  auto check = [&](int r, int c) -> bool {
    if (g[r][c] == '.' && d[r][c] < md[r][c]) {
      cout << "YES\n";
      int cr = r, cc = c;
      deque<char> ans;
      while (true) {
        if (move[cr][cc] == -1)
          break;

        ans.push_front(dir[move[cr][cc]]);
        auto tr = cr, tc = cc;
        cr -= dr[move[tr][tc]];
        cc -= dc[move[tr][tc]];
      }
      cout << ans.size() << '\n';
      for (auto mv : ans) {
        cout << mv;
      }
      if (!ans.empty())
        cout << '\n';
      return true;
    }
    return false;
  };

  for (auto r : {0, n - 1}) {
    for (int c{}; c < m; ++c) {
      if (check(r, c))
        return 0;
    }
  }

  for (auto c : {0, m - 1}) {
    for (int r{}; r < n; ++r) {
      if (check(r, c))
        return 0;
    }
  }

  cout << "NO\n";
}
