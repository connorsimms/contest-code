#include <bits/stdc++.h>
using namespace std;

constexpr array<int, 2> dr = {0, 1}, dc = {1, 0};

int main() {
  int n;
  cin >> n;

  vector<vector<char>> g(n, vector<char>(n));
  vector<vector<bool>> seen(n, vector<bool>(n));

  vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(n));

  for (int i{}; i < n; ++i) {
    for (int j{}; j < n; ++j) {
      cin >> g[i][j];
    }
  }

  using T = tuple<char, int, int>;
  vector<T> v1, v2;

  v1.emplace_back(g[0][0], 0, 0);
  seen[0][0] = true;

  while (!v1.empty()) {
    char mc = 'Z';

    for (auto [l, r, c] : v1) {
      for (int i{}; i < 2; ++i) {
        auto nr = r + dr[i], nc = c + dc[i];
        if (nr < n && nc < n && !seen[nr][nc]) {
          seen[nr][nc] = true;
          mc = min(mc, g[nr][nc]);
          v2.emplace_back(g[nr][nc], nr, nc);
          par[nr][nc].first = r;
          par[nr][nc].second = c;
        }
      }
    }

    v1.clear();

    for (auto [l, r, c] : v2) {
      if (l == mc)
        v1.emplace_back(l, r, c);
    }

    v2.clear();
  }

  deque<char> ans;
  int cr = n - 1, cc = n - 1;
  while (cr || cc) {
    ans.push_front(g[cr][cc]);
    auto tr = cr, tc = cc;
    cr = par[tr][tc].first;
    cc = par[tr][tc].second;
  }
  ans.push_front(g[0][0]);

  for (auto c : ans)
    cout << c;
  cout << '\n';
}
