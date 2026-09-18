#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = numeric_limits<ll>::max();

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  bool valid = true;
  vector<tuple<ll, int, int>> edges;
  vector<vector<ll>> distance(N, vector<ll>(N));

  for (int i{}; i < N; ++i) {
    for (int j{}; j < N; ++j) {
      cin >> distance[i][j];

      if (i < j) {
        if (distance[i][j] <= 0) {
          valid = false;
        }
      }

      if (i == j && distance[i][j]) {
        valid = false;
      }

      if (i > j && distance[i][j] != distance[j][i]) {
        valid = false;
      }
    }
  }

  if (!valid) {
    cout << "NO\n";
    return 0;
  }

  if (N == 1) {
    cout << "YES\n";
    return 0;
  }

  vector<vector<pair<int, ll>>> adj(N);
  vector<pair<ll, int>> min_edge(N, {INF, -1});
  vector<bool> seen(N);
  min_edge[0].first = 0;

  for (int i{}; i < N; ++i) {
    int v = -1;
    for (int j{}; j < N; ++j) {
      if (!seen[j] && (v == -1 || (min_edge[j].first < min_edge[v].first)))
        v = j;
    }

    if (min_edge[v].first == INF) {
      cout << "NO\n";
      return 0;
    }

    seen[v] = true;
    if (min_edge[v].second != -1) {
      adj[v].emplace_back(min_edge[v].second, min_edge[v].first);
      adj[min_edge[v].second].emplace_back(v, min_edge[v].first);
    }

    for (int nxt{}; nxt < N; ++nxt) {
      if (!seen[nxt] && distance[v][nxt] < min_edge[nxt].first) {
        min_edge[nxt] = {distance[v][nxt], v};
      }
    }
  }

  vector<ll> d(N);
  auto bfs = [&](int s) {
    fill(begin(d), end(d), 0);

    queue<int> q;
    d[s] = 0;
    q.push(s);

    while (!q.empty()) {
      auto f = q.front();
      q.pop();

      for (auto [next, cost] : adj[f]) {
        if (!d[next] && next != s) {
          d[next] = d[f] + cost;
          q.push(next);
        }
      }
    }

    return std::equal(begin(d), end(d), begin(distance[s]), end(distance[s]));
  };

  for (int i{}; i < N; ++i) {
    if (!bfs(i)) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}
