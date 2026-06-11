#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n, m, a, b, c;
  cin >> n >> m >> a >> b >> c;

  vector<ll> p(m);
  for (int i = 0; i < m; ++i) {
    cin >> p[i];
  }
  sort(p.begin(), p.end());

  vector<ll> pp(m + 1);
  for (int i = 1; i <= m; ++i) {
    pp[i] += p[i - 1];
    pp[i] += pp[i - 1];
  }

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> distA(n + 1, -1), distB(n + 1, -1), distC(n + 1, -1);

  auto find_dist = [&](int source, vector<int> &dist) {
    queue<int> q;
    dist[source] = 0;
    q.push(source);

    while (!q.empty()) {
      int f = q.front();
      q.pop();
      for (auto next : adj[f]) {
        if (dist[next] == -1) {
          dist[next] = dist[f] + 1;
          q.push(next);
        }
      }
    }
  };

  find_dist(a, distA);
  find_dist(b, distB);
  find_dist(c, distC);

  ll bestPrice = numeric_limits<ll>::max();

  for (int x = 1; x <= n; ++x) {
    ll totPrice = 0;

    ll e1 = distA[x];
    ll e2 = distB[x];
    ll e3 = distC[x];

    if (e1 + e2 + e3 > m)
      continue;

    totPrice += pp[e2] * 2;
    totPrice += pp[e1 + e2] - pp[e2];
    totPrice += pp[e1 + e2 + e3] - pp[e1 + e2];

    bestPrice = min(bestPrice, totPrice);
  }

  cout << bestPrice << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
