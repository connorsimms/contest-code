#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n, x1, x2, k;
  cin >> n >> x1 >> x2 >> k;
  --x1, --x2;

  if (n == 2 || n == 3) {
    cout << 1 << '\n';
    return;
  }

  int dist = min(abs(x1 - x2), n - abs(x1 - x2));

  cout << dist + k << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
