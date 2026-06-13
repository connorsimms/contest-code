#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i <= n; ++i) {
    int k;
    cin >> k;
    for (int j = 1; j <= k; ++j) {
      int a;
      cin >> a;
      adj[a].push_back(i);
    }
  }

  for (int i = 1; i <= n; ++i) {
    sort(adj[i].begin(), adj[i].end());

    cout << adj[i].size();
    for (auto x : adj[i]) {
      cout << ' ' << x;
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
