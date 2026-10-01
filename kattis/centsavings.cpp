#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

int main() {
  int n, d;
  cin >> n >> d;

  vector<int> p(n + 1);

  for (int i{1}; i <= n; ++i)
    cin >> p[i];

  vector<int> pf(p);
  for (int i{1}; i <= n; ++i)
    pf[i] += pf[i - 1];

  vector<vector<int>> mem(d + 1, vector<int>(n + 1, INF));

  auto dp = [&](auto &&rec, int d_used, int i) -> int {
    if (i == n + 1) {
      return 0;
    }

    if (d_used == d) {
      int sum = pf[n] - pf[i - 1];
      sum = ((sum + 5) / 10) * 10;
      return mem[d_used][i] = sum;
    }

    if (mem[d_used][i] != INF)
      return mem[d_used][i];

    for (int next{i + 1}; next <= n + 1; ++next) {
      int sum = pf[next - 1] - pf[i - 1];
      sum = ((sum + 5) / 10) * 10;
      mem[d_used][i] = min(mem[d_used][i], rec(rec, d_used + 1, next) + sum);
    }

    return mem[d_used][i];
  };

  cout << dp(dp, 0, 1) << '\n';
}
