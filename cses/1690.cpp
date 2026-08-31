#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> adj(N);
  vector<vector<ll>> mem(N, vector<ll>(1 << N));

  fill(begin(mem[0]), end(mem[0]), -1);
  mem[0][1] = 1;

  for (int i{}; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[v].push_back(u);
  }

  auto dp = [&](auto &&rec, int last, int mask) -> ll {
    if (!(mask & (1 << last)))
      return mem[last][mask] = -1;

    if (mem[last][mask])
      return mem[last][mask];

    for (auto next : adj[last]) {
      auto nxt = rec(rec, next, mask ^ (1 << last));

      if (nxt != -1) {
        mem[last][mask] += nxt;
        mem[last][mask] %= MOD;
      }
    }

    if (!mem[last][mask])
      mem[last][mask] = -1;

    return mem[last][mask];
  };

  auto ans = dp(dp, N - 1, (1 << N) - 1);
  if (ans == -1)
    ans = 0;

  cout << ans << '\n';
}
