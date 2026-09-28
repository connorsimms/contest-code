#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1);

  for (int i{1}; i <= m; ++i) {
    int x;
    cin >> x;
    adj[x].emplace_back(i, x + 1);
    adj[x + 1].emplace_back(i, x);
  }

  vector<int> mp(n + 1);

  for (int i{1}; i <= n; ++i) {
    int cur = i;
    int dep = 0;

    while (true) {
      auto it = upper_bound(begin(adj[cur]), end(adj[cur]), make_pair(dep, 0));

      if (it == end(adj[cur]))
        break;

      dep = it->first + 1;
      cur = it->second;
    }

    mp[cur] = i;
  }

  for (int i{1}; i <= n; ++i) {
    cout << mp[i] << '\n';
  }

  return 0;
}
