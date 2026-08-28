#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = numeric_limits<ll>::max() / 2;

int main() {
  int N;
  cin >> N;

  vector<ll> h(N);
  for (int i{}; i < N; ++i)
    cin >> h[i];

  vector<ll> mem(N, INF);
  mem[0] = 0;

  auto dp = [&](auto &&rec, int c) -> ll {
    if (mem[c] != INF)
      return mem[c];

    auto ans = rec(rec, c - 1) + abs(h[c] - h[c - 1]);

    if (c - 2 >= 0) {
      ans = min(ans, rec(rec, c - 2) + abs(h[c] - h[c - 2]));
    }

    return mem[c] = ans;
  };

  cout << dp(dp, N - 1) << '\n';
}
