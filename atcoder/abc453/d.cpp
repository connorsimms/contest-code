#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

constexpr array<int, 4> dr = {-1, 0, 1, 0};
constexpr array<int, 4> dc = {0, 1, 0, -1};
constexpr array<char, 4> itoc{'U', 'R', 'D', 'L'};

void solve() {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> g(h, vector<char>(w));
  vector<vector<int>> seen(h, vector<int>(w));
  vector<vector<pair<int, int>>> parent(h, vector<pair<int, int>>(w, {-1, -1}));
  vector<vector<char>> direction(h, vector<char>(w));

  int startRow, startCol, endRow, endCol;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> g[i][j];
      if (g[i][j] == 'S') {
        startRow = i;
        startCol = j;
      }
      if (g[i][j] == 'G') {
        endRow = i;
        endCol = j;
      }
    }
  }

  bool found = false;

  vector<char> ans;

  auto dfs = [&](int row, int col, int prevDir, auto &&self) {
    char curr = g[row][col];

    if (curr == 'G') {
      found = true;
    }

    if (found)
      return;

    for (int nextDir = 0; nextDir < 4; ++nextDir) {
      if (curr == 'o' && nextDir != prevDir)
        continue;

      if (curr == 'x' && nextDir == prevDir)
        continue;

      int newRow = row + dr[nextDir];
      int newCol = col + dc[nextDir];

      if (newRow < 0 || newRow >= h || newCol < 0 || newCol >= w)
        continue;

      if (g[newRow][newCol] == '#')
        continue;

      if (!(seen[newRow][newCol] & (1 << nextDir))) {
        seen[newRow][newCol] |= (1 << nextDir);
        self(newRow, newCol, nextDir, self);

        if (found) {
          direction[newRow][newCol] = itoc[nextDir];
          parent[newRow][newCol].first = row;
          parent[newRow][newCol].second = col;
          ans.push_back(itoc[nextDir]);
          return;
        }
      }
    }
  };

  seen[startRow][startCol] = (1 << 4) - 1;
  dfs(startRow, startCol, -1, dfs);

  if (seen[endRow][endCol]) {
    cout << "Yes\n";
    reverse(ans.begin(), ans.end());
    for (auto c : ans)
      cout << c;
    cout << '\n';
  } else {
    cout << "No\n";
  }
}

int main() { solve(); }
