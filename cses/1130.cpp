#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n + 1);

  for (int i{}; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<vector<int>> child(n + 1);

  vector<bool> seen(n + 1);
  queue<int> q;
  seen[1] = true;
  q.push(1);
  while (!q.empty()) {
    auto f = q.front();
    q.pop();
    for (auto c : adj[f]) {
      if (!seen[c]) {
        seen[c] = true;
        q.push(c);
        child[f].push_back(c);
      }
    }
  }

  vector<int> memNone(n + 1), memOne(n + 1);

  auto dp = [&](auto &&rec, int v) -> void {
    for (auto c : child[v]) {
      rec(rec, c);
      memNone[v] += max(memNone[c], memOne[c]);
    }

    for (auto c : child[v]) {
      int sum = 0;

      sum += memNone[c] + 1;

      sum += memNone[v] - max(memNone[c], memOne[c]);

      memOne[v] = max(memOne[v], sum);
    }
  };

  dp(dp, 1);

  cout << max(memNone[1], memOne[1]) << '\n';
}
