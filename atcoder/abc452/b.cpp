#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> g(h, vector<char>(w, '.'));

  for (int i = 0; i < h; ++i)
    g[i][0] = '#';
  for (int i = 0; i < h; ++i)
    g[i][w - 1] = '#';
  for (int i = 0; i < w; ++i)
    g[0][i] = '#';
  for (int i = 0; i < w; ++i)
    g[h - 1][i] = '#';

  for (auto r : g) {
    for (auto c : r)
      cout << c;
    cout << '\n';
  }
}
