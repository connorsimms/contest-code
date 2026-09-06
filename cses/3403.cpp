#include <bits/stdc++.h>
using namespace std;

int main() {
  size_t n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);
  for (size_t i{}; i < n; ++i)
    cin >> a[i];
  for (size_t i{}; i < m; ++i)
    cin >> b[i];

  vector<vector<int>> mem(n + 1, vector<int>(m + 1, -1));
  vector<vector<pair<int, int>>> par(n + 1, vector<pair<int, int>>(m + 1));
  vector<vector<bool>> use(n + 1, vector<bool>(m + 1));

  for (size_t i{}; i <= n; ++i)
    mem[i][0] = 0;

  for (size_t i{}; i <= m; ++i)
    mem[0][i] = 0;

  auto dp = [&](auto &&rec, int i, int j) {
    if (mem[i][j] != -1)
      return mem[i][j];

    if (a[i - 1] == b[j - 1]) {
      auto x = rec(rec, i - 1, j - 1);
      if (mem[i][j] < x + 1) {
        mem[i][j] = x + 1;
        par[i][j].first = i - 1;
        par[i][j].second = j - 1;
        use[i][j] = true;
      }
    } else {
      auto y = rec(rec, i, j - 1);
      if (mem[i][j] < y) {
        mem[i][j] = y;
        par[i][j].first = i;
        par[i][j].second = j - 1;
      }
      auto z = rec(rec, i - 1, j);
      if (mem[i][j] < z) {
        mem[i][j] = z;
        par[i][j].first = i - 1;
        par[i][j].second = j;
      }
    }

    return mem[i][j];
  };

  cout << dp(dp, n, m) << '\n';

  deque<int> ans;
  int ci = n, cj = m;
  while (ci && cj) {
    if (use[ci][cj])
      ans.push_front(a[ci - 1]);
    auto ti = ci, tj = cj;
    ci = par[ti][tj].first;
    cj = par[ti][tj].second;
  }

  for (auto x : ans)
    cout << x << ' ';
  cout << '\n';
}
