#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;

int main() {
  constexpr array<int, 4> dr = {-1, 1, 0, 0};
  constexpr array<int, 4> dc = {0, 0, -1, 1};

  int H, W;
  cin >> H >> W;

  V<V<char>> g(H, V<char>(W));

  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j)
      cin >> g[i][j];

  V<V<bool>> seen(H, V<bool>(W));

  auto find = [&](int R, int C) {
    queue<pair<int, int>> q;

    q.emplace(R, C);

    bool valid = true;

    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();

      for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < H && nc >= 0 && nc < W && !seen[nr][nc] &&
            g[nr][nc] == '.') {
          if (nr == 0 || nr == H - 1 || nc == 0 || nc == W - 1)
            valid = false;
          q.emplace(nr, nc);
          seen[nr][nc] = true;
        }
      }
    }

    return valid;
  };

  int ans = 0;
  for (int i = 1; i < H - 1; ++i) {
    for (int j = 1; j < W - 1; ++j) {
      if (g[i][j] == '.' && !seen[i][j]) {
        if (find(i, j))
          ++ans;
      }
    }
  }

  cout << ans << '\n';
}
