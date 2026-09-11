#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  size_t n;
  ll a, b;
  cin >> n >> a >> b;

  map<int, int> m;
  for (size_t i{}; i < n; ++i) {
    int x;
    cin >> x;
    m[x] = i;
  }

  vector<int> col(n, 2);

  auto dfs = [&](auto &&rec, int v, int c) -> bool {
    if (!m.count(v))
      return false;

    auto &cur_col = col[m[v]];

    if (cur_col != 2 && cur_col != c)
      return false;

    if (cur_col == c)
      return true;

    cur_col = c;

    if (c == 0) {
      if (!rec(rec, a - v, 0)) {
        cur_col = 2;
        return false;
      }

      auto bi = m.find(b - v);
      if (bi != end(m)) {
        if (!(rec(rec, b - v, 0))) {
          cur_col = 2;
          return false;
        }
      }
    } else if (c == 1) {
      if (!rec(rec, b - v, 1)) {
        cur_col = 2;
        return false;
      }

      auto ai = m.find(a - v);
      if (ai != end(m)) {
        if (!(rec(rec, a - v, 1))) {
          cur_col = 2;
          return false;
        }
      }
    }

    return true;
  };

  for (auto [x, i] : m) {
    if (dfs(dfs, x, 0))
      continue;

    if (dfs(dfs, x, 1))
      continue;

    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  for (auto x : col) {
    cout << x << ' ';
  }
  cout << '\n';
}
