#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> sub(n + 1);

  for (int i{2}; i <= n; ++i) {
    int p;
    cin >> p;
    sub[p].push_back(i);
  }

  vector<int> ans(n + 1);

  auto dfs = [&](auto &&rec, int v) -> int {
    for (auto s : sub[v]) {
      ans[v] += rec(rec, s) + 1;
    }

    return ans[v];
  };

  dfs(dfs, 1);

  bool first = true;
  for (int i{1}; i <= n; ++i) {
    if (!first)
      cout << ' ';
    first = false;
    cout << ans[i];
  }
  cout << '\n';
}
