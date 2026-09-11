#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> out(n + 1);
  vector<int> ind(n + 1);

  for (int i{}; i < m; ++i) {
    int a, b;
    cin >> a >> b;

    out[a].push_back(b);
    ++ind[b];
  }

  queue<int> q;
  for (int i{1}; i <= n; ++i) {
    if (!ind[i])
      q.push(i);
  }

  vector<int> ans;

  while (!q.empty()) {
    auto f = q.front();

    ans.push_back(f);

    q.pop();

    for (auto nxt : out[f]) {
      if (--ind[nxt] == 0) {
        q.push(nxt);
      }
    }
  }

  if (int(ans.size()) != n) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  bool first = true;
  for (auto x : ans) {
    if (!first)
      cout << ' ';
    first = false;

    cout << x;
  }
  cout << '\n';
}
