#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<int>> v(h + 2, vector<int>(w + 2));

  array<int, 4> dr = {1, -1, 0, 0};
  array<int, 4> dc = {0, 0, 1, -1};

  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      for (int k = 0; k < 4; ++k) {
        ++v[i + dr[k]][j + dc[k]];
      }
    }
  }

  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j)
      cout << v[i][j] << ' ';
    cout << '\n';
  }
}
