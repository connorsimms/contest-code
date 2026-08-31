#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1e9;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> adj(N);

  for (int i{}; i < N; ++i) {
    adj[i] |= (1 << i);
  }

  for (int i{}; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;

    adj[a] |= (1 << b);
    adj[b] |= (1 << a);
  }

  vector<ll> mem(1 << N);

  mem[0] = 0;

  for (int s{1}; s < (1 << N); ++s) {
    bool c = true;

    for (int i{}; i < N && c; ++i) {
      if (s & (1 << i)) {
        if ((adj[i] & s) != s)
          c = false;
      }
    }

    if (c)
      mem[s] = 1;
    else
      mem[s] = INF;
  }

  auto dp = [&](auto &&rec, int s) -> ll {
    if (mem[s] != INF)
      return mem[s];

    for (int sub{s}; sub > 0; sub = (sub - 1) & s) {
      auto comp = s ^ sub;

      if (sub == s || comp == s)
        continue;

      mem[s] = min(mem[s], rec(rec, sub) + rec(rec, comp));
    }

    return mem[s];
  };

  cout << dp(dp, (1 << N) - 1) << '\n';
}
