#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll INF = numeric_limits<ll>::max() / 2;

void find(int s, vector<vector<pair<int, ll>>> &adj, vector<ll> &d) {
  set<pair<ll, int>> q;
  d[s] = 0;
  q.emplace(0, s);

  while (!q.empty()) {
    auto it = q.begin();
    auto [cc, cv] = *it;
    q.erase(it);

    for (auto [nv, nc] : adj[cv]) {
      if (d[cv] + nc < d[nv]) {
        q.erase({d[nv], nv});
        d[nv] = d[cv] + nc;
        q.emplace(d[nv], nv);
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> adj(n + 1), rev(n + 1);

  for (int i{}; i < m; ++i) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    adj[a].emplace_back(b, c);
    rev[b].emplace_back(a, c);
  }

  vector<ll> d1(n + 1, INF), d2(n + 1, INF);

  find(1, adj, d1);
  find(n, rev, d2);

  ll best = INF;

  for (int i{1}; i <= n; ++i) {
    for (auto [j, c] : adj[i]) {
      ll x = d1[i] + d2[j];
      ll tot = c / 2 + x;
      best = min(best, tot);
    }
  }

  cout << best << '\n';
}
