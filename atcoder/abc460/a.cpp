#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  int ans = 0;
  while (m) {
    ++ans;
    m = n % m;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
