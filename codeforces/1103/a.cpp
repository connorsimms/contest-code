#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;
  int mn = 100;
  int mx = -100;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    mn = min(mn, x);
    mx = max(mx, x);
  }

  cout << mx - mn + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
