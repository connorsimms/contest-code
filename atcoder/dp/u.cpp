#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<vector<ll>> c(N, vector<ll>(N));
  for (int i{}; i < N; ++i) {
    for (int j{}; j < N; ++j) {
      cin >> c[i][j];
    }
  }

  vector<ll> mem(1 << N, -1);
  vector<ll> score(1 << N, 0);
  mem[0] = 0;

  for (int sub{(1 << N) - 1}; sub > 0; sub = (sub - 1) & ((1 << N) - 1)) {
    ll s{};

    for (int i{}; i < N; ++i) {
      if (!(sub & (1 << i)))
        continue;
      for (int j{i + 1}; j < N; ++j) {
        if (!(sub & (1 << j)))
          continue;

        s += c[i][j];
      }
    }

    score[sub] = s;
  }

  auto dp = [&](auto &&rec, int mask) {
    if (mem[mask] != -1)
      return mem[mask];

    for (int cmp{mask}; cmp > 0; cmp = (cmp - 1) & mask) {
      int sub = mask ^ cmp;
      mem[mask] = max(mem[mask], rec(rec, sub) + score[cmp]);
    }

    return mem[mask];
  };

  cout << dp(dp, (1 << N) - 1) << '\n';
}
