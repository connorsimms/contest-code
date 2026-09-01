#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e9;

int main() {
  int N, P, K;
  cin >> N >> P >> K;

  vector<vector<ll>> mem(1 << P, vector<ll>(N, -1));

  vector<pair<ll, int>> a(N);
  for (int i{}; i < N; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(rbegin(a), rend(a));

  vector<vector<ll>> s(P, vector<ll>(N));
  for (int i{}; i < N; ++i)
    for (int j{}; j < P; ++j)
      cin >> s[j][i];

  for (int i{}; i < (1 << P); ++i)
    mem[i][0] = -INF;

  mem[0][0] = a[0].first;
  for (int i{}; i < P; ++i)
    mem[(1 << i)][0] = s[i][a[0].second];

  auto dp = [&](auto &&rec, int mask, int n) -> ll {
    if (mem[mask][n] != -1)
      return mem[mask][n];

    auto id = a[n].second;

    bool fullAud = n - __builtin_popcount(mask) >= K;

    {
      auto nxt = rec(rec, mask, n - 1);
      if (nxt != -INF)
        mem[mask][n] = max(mem[mask][n], nxt + !fullAud * a[n].first);
    }

    for (int i{}; i < P; ++i) {
      if (mask & (1 << i)) {
        auto nxt = rec(rec, mask ^ (1 << i), n - 1);
        if (nxt != -INF)
          mem[mask][n] = max(mem[mask][n], nxt + s[i][id]);
      }
    }

    if (mem[mask][n] == -1)
      mem[mask][n] = -INF;

    return mem[mask][n];
  };

  cout << dp(dp, (1 << P) - 1, N - 1) << '\n';
}
