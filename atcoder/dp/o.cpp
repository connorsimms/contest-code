#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

int main() {
  int N;
  cin >> N;

  vector<int> adj(N);
  vector<vector<ll>> mem(N, vector<ll>(1 << N));

  fill(begin(mem[0]), end(mem[0]), -1);

  for (int i{}; i < N; ++i) {
    for (int j{}; j < N; ++j) {
      int x;
      cin >> x;

      adj[i] |= (x << j);

      if (x && !i) {
        mem[i][(1 << j)] = 1;
      }
    }
  }

  auto dp = [&](auto &&rec, int n, int mask) -> ll {
    if (mem[n][mask])
      return mem[n][mask];

    for (int i{}; i < N; ++i) {
      if (adj[n] & (1 << i)) {
        auto nxt = rec(rec, n - 1, mask ^ (1 << i));
        if (nxt != -1) {
          mem[n][mask] += nxt;
          mem[n][mask] %= MOD;
        }
      }
    }

    if (!mem[n][mask])
      return mem[n][mask] = -1;

    return mem[n][mask];
  };

  auto ans = dp(dp, N - 1, (1 << N) - 1);
  if (ans == -1)
    ans = 0;

  cout << ans << '\n';
}
