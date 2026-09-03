#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  vector<bool> seen(n + 1);
  vector<int> dist(n + 1), par(n + 1);

  for (int i{}; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  queue<int> q;
  q.push(1);
  seen[1] = true;
  dist[1] = 0;
  par[1] = -1;

  while (!q.empty()) {
    auto f = q.front();
    q.pop();

    for (auto next : adj[f]) {
      if (!seen[next]) {
        seen[next] = true;
        dist[next] = dist[f] + 1;
        par[next] = f;
        q.push(next);
      }
    }
  }

  if (!dist[n])
    cout << "IMPOSSIBLE\n";
  else {
    int cur = n;
    vector<int> ans;

    while (cur != -1) {
      ans.push_back(cur);
      cur = par[cur];
    }

    reverse(begin(ans), end(ans));

    cout << ans.size() << '\n';
    bool first = true;
    for (auto x : ans) {
      if (!first)
        cout << ' ';
      first = false;
      cout << x;
    }
    cout << '\n';
  }
}
