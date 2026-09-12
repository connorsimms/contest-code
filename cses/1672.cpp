#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll INF = numeric_limits<ll>::max() / 2 - 1;

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<ll>> d(n + 1, vector<ll>(n + 1, INF));

  for (int i{}; i < m; ++i) {
    ll a, b, c;
    cin >> a >> b >> c;

    d[a][b] = min(d[a][b], c);
    d[b][a] = min(d[b][a], c);
  }

  for (int k{1}; k <= n; ++k) {
    for (int i{1}; i <= n; ++i) {
      for (int j{1}; j <= n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  for (int i{}; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    auto ans = d[a][b];
    if (ans == INF)
      ans = -1;
    if (a == b)
      ans = 0;
    cout << ans << '\n';
  }
}
