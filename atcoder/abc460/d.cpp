#include <bits/stdc++.h>
using namespace std;

using ll = long long;

array<int, 8> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
array<int, 8> dc = {-1, 0, 1, -1, 1, -1, 0, 1};

void solve() {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> grid(h, vector<char>(w));

  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      cin >> grid[i][j];

  vector<vector<int>> depth(h, vector<int>(w));
  vector<vector<bool>> seen(h, vector<bool>(w));
  queue<pair<int, int>> q;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (grid[i][j] == '.')
        continue;

      if (seen[i][j])
        continue;

      bool hasWhite = false;
      for (int k = 0; k < 8; ++k) {
        int r = i + dr[k];
        int c = j + dc[k];

        if (r >= 0 && r < h && c >= 0 && c < w && grid[r][c] == '.')
          hasWhite = true;
      }
      if (hasWhite) {
        q.emplace(i, j);
        seen[i][j] = true;
      }
    }
  }

  if (q.size() == h * w || q.empty()) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cout << '.';
      }
      cout << '\n';
    }
    return;
  }

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    for (int i = 0; i < 8; ++i) {
      int nr = r + dr[i];
      int nc = c + dc[i];

      if (nr >= 0 && nr < h && nc >= 0 && nc < w && !seen[nr][nc]) {
        seen[nr][nc] = true;
        depth[nr][nc] = depth[r][c] + 1;
        q.emplace(nr, nc);
      }
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (depth[i][j] % 2 == 0)
        cout << '#';
      else
        cout << '.';
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
