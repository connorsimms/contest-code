#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  int cuts = min(k - 1, 2);

  vector<int> a(n);
  vector<int> x(n);
  int xTot = 0;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    x[i] = a[i];
    xTot ^= a[i];
  }

  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }

  if (xTot == 0) {
    cout << "YES\n";
    return;
  }

  if (cuts < 2) {
    cout << "NO\n";
    return;
  }

  vector<int> par(n);
  vector<vector<int>> chi(n);

  auto dfs = [&](int pre, int cur, auto &&self) -> int {
    for (auto next : adj[cur]) {
      par[cur] = pre;
      if (next != pre) {
        chi[cur].push_back(next);
        x[cur] ^= self(cur, next, self);
      }
    }
    if (cur != 0 && x[cur] == xTot && cuts > 0) {
      --cuts;
      return 0;
    } else {
      return x[cur];
    }
  };

  dfs(-1, 0, dfs);

  if (cuts == 0)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
