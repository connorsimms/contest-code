#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

constexpr ll MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> child(n + 1);
  vector<int> parent(n + 1);
  parent[1] = 0;
  child[0].push_back(1);

  for (int i = 1; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0)
      continue;

    child[i].push_back(a);
    child[i].push_back(b);
    parent[a] = parent[b] = i;
  }

  vector<ll> size(n + 1);

  auto findSize = [&](int v, auto &&self) -> int {
    size[v] += 1;
    for (auto c : child[v]) {
      size[v] += self(c, self);
    }
    return size[v];
  };

  findSize(0, findSize);

  vector<ll> moves(n + 1);
  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int f = q.front();
    q.pop();

    for (auto c : child[f]) {
      moves[c] = moves[f] + 1 + (size[c] - 1) * 2;
      moves[c] %= MOD;
      q.push(c);
    }
  }

  for (int i = 1; i <= n; ++i)
    cout << moves[i] % MOD << ' ';
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
