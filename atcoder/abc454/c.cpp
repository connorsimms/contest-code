#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
  }

  vector<bool> seen(n + 1, false);
  queue<int> q;
  seen[1] = true;
  q.push(1);

  int ans = 0;

  while (!q.empty()) {
    int f = q.front();
    q.pop();
    ++ans;

    for (auto x : adj[f]) {
      if (!seen[x]) {
        seen[x] = true;
        q.push(x);
      }
    }
  }

  cout << ans << '\n';
}
