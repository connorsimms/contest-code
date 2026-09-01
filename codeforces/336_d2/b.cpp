#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i{}; i < n; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> mem(n, vector<int>(n, INF));

  auto dp = [&](auto &&rec, int l, int r) -> int {
    if (mem[l][r] != INF)
      return mem[l][r];

    if (l == r)
      return mem[l][r] = 1;

    if (l + 1 == r)
      return mem[l][r] = 1 + (a[l] != a[r]);

    mem[l][r] = rec(rec, l + 1, r) + 1;

    if (a[l] == a[l + 1])
      mem[l][r] = min(mem[l][r], rec(rec, l + 2, r) + 1);

    for (int i{l + 2}; i <= r; ++i) {
      if (a[i] == a[l]) {
        auto res = rec(rec, l + 1, i - 1);
        if (i + 1 <= r)
          res += rec(rec, i + 1, r);
        mem[l][r] = min(mem[l][r], res);
      }
    }

    return mem[l][r];
  };

  cout << dp(dp, 0, n - 1) << '\n';
}
