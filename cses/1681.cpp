#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> edges;

  {
    vector<vector<int>> out(n + 1);

    for (int i{}; i < m; ++i) {
      int a, b;
      cin >> a >> b;

      out[a].push_back(b);
    }

    vector<bool> seen(n + 1);
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
      auto f = q.front();
      q.pop();

      for (auto nxt : out[f]) {
        edges.emplace_back(f, nxt);
        if (!seen[nxt]) {
          seen[nxt] = true;
          q.push(nxt);
        }
      }
    }
  }

  vector<vector<int>> out(n + 1);
  vector<int> ind(n + 1);
  for (auto [a, b] : edges) {
    out[a].push_back(b);
    ++ind[b];
  }

  vector<ll> mem(n + 1);
  mem[1] = 1;
  queue<int> q;
  q.push(1);

  while (!q.empty()) {
    auto f = q.front();
    q.pop();

    for (auto nxt : out[f]) {
      mem[nxt] += mem[f];
      mem[nxt] %= MOD;
      if (--ind[nxt] == 0) {
        q.push(nxt);
      }
    }
  }

  cout << mem[n] << '\n';
}
