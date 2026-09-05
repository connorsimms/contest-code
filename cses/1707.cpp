#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> adj(N + 1);

  for (int i{}; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  auto check = [&](int v) -> int {
    vector<bool> seen(N + 1);
    vector<int> dist(N + 1), par(N + 1);
    queue<int> q;

    q.push(v);
    seen[v] = true;
    dist[v] = 0;

    int best = INF;

    while (!q.empty()) {
      auto f = q.front();
      q.pop();

      for (auto next : adj[f]) {
        if (!seen[next]) {
          seen[next] = true;
          dist[next] = dist[f] + 1;
          par[next] = f;
          q.push(next);
        } else if (next != par[f]) {
          best = min(best, dist[next] + dist[f] + 1);
        }
      }
    }

    return best;
  };

  int ans = INF;
  for (int i{1}; i <= N; ++i) {
    ans = min(ans, check(i));
  }

  if (ans == INF)
    ans = -1;

  cout << ans << '\n';
}
