#include <bits/stdc++.h>
using namespace std;

array<int, 256> DR = {-1, 0, 1, 0};
array<int, 256> DC = {0, -1, 0, 1};

constexpr void init_dr_dc() {
  DR['N'] = -1, DC['N'] = 0;
  DR['W'] = 0, DC['W'] = -1;
  DR['S'] = 1, DC['S'] = 0;
  DR['E'] = 0, DC['E'] = 1;
}

int main() {
  init_dr_dc();

  int W, H;
  cin >> W >> H;

  {
    string junk;
    getline(cin, junk);
  }

  vector<vector<char>> grid(H, vector<char>(W));

  int startRow{-1}, startCol{-1};

  for (int i{}; i < H; ++i) {
    string ln;
    getline(cin, ln);
    for (int j{}; j < W; ++j) {
      grid[i][j] = ln[j];

      if (ln[j] == 'S')
        startRow = i, startCol = j;
    }
  }

  string directions;
  cin >> directions;

  auto ans(grid);
  vector<vector<int>> regDist(H, vector<int>(W)), avoidDist(H, vector<int>(W));

  auto bfs = [&](vector<vector<int>> &d, bool avoid) {
    vector<vector<bool>> seen(H, vector<bool>(W));
    queue<pair<int, int>> q;
    q.emplace(startRow, startCol);
    seen[startRow][startCol] = true;

    while (!q.empty()) {
      auto [cr, cc] = q.front();
      q.pop();

      if (avoid && d[cr][cc] == (int)directions.size() &&
          regDist[cr][cc] == d[cr][cc]) {
        ans[cr][cc] = '!';
        continue;
      }

      for (int i{}; i < 4; ++i) {
        auto dr = DR[i], dc = DC[i];
        auto nr = cr + dr, nc = cc + dc;

        if (nr < 0 || nr >= H || nc < 0 || nc >= W)
          continue;

        if (grid[nr][nc] != '.')
          continue;

        if (seen[nr][nc])
          continue;

        if (avoid) {
          auto dir_idx = d[cr][cc];
          auto avoid_dir = directions[dir_idx];
          if (dr == DR[avoid_dir] && dc == DC[avoid_dir]) {
            continue;
          }
        }

        q.emplace(nr, nc);
        seen[nr][nc] = true;
        d[nr][nc] = d[cr][cc] + 1;
      }
    }
  };

  bfs(regDist, false);
  bfs(avoidDist, true);

  for (const auto &r : ans) {
    for (auto c : r) {
      cout << c;
    }
    cout << '\n';
  }
}
