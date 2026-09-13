#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll INF = numeric_limits<ll>::max();

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1);

  vector<ll> d(n + 1, INF);
  d[1] = 0;

  for (int i{}; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    ll c;
    cin >> c;

    adj[a].emplace_back(c, b);
  }

  set<tuple<ll, int>> s;
  s.emplace(0, 1);

  while (!s.empty()) {
    auto it = s.begin();
    auto [c, cur] = *it;
    s.erase(it);

    for (auto [cn, nxt] : adj[cur]) {
      if (d[cur] + cn < d[nxt]) {
        s.erase({d[nxt], nxt});
        d[nxt] = d[cur] + cn;
        s.emplace(d[nxt], nxt);
      }
    }
  }

  for (int i{1}; i <= n; ++i) {
    cout << d[i] << ' ';
  }
  cout << '\n';
}
