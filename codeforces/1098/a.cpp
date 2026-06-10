#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;
  vector<int> f(3);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++f[x];
  }

  int ans = 0;
  ans += f[0];
  int pair = min(f[1], f[2]);
  ans += pair;
  f[1] -= pair;
  f[2] -= pair;
  ans += f[1] / 3;
  ans += f[2] / 3;

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
