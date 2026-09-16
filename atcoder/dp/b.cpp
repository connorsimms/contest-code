#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9 + 1;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> h(N + 1);
  for (int i{1}; i <= N; ++i) {
    cin >> h[i];
  }

  vector<int> mem(N + 1, INF);
  mem[1] = 0;

  auto dp = [&](auto &&rec, int n) {
    if (mem[n] != INF) {
      return mem[n];
    }

    for (int i{1}; i <= K; ++i) {
      if (i >= n)
        break;

      mem[n] = min(mem[n], rec(rec, n - i) + abs(h[n] - h[n - i]));
    }

    return mem[n];
  };

  cout << dp(dp, N) << '\n';
}
