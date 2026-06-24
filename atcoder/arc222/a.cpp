#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
template <typename T> using v = vector<T>;

void solve() {
  int n, m;
  cin >> n >> m;

  v<int> ans(n);
  v<pair<int, int>> inter;

  int mx = 1;

  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    inter.emplace_back(l, r);
    mx = max(mx, r - l + 1);
  }

  ans[0] = 1;
  for (int i = 1; i < n; ++i) {
    ans[i] = ans[i - 1] % mx + 1;
  }

  for (auto x : ans)
    cout << x << ' ';
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
