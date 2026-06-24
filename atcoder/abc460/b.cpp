#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

  ll d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

  if (d < (r1 - r2) * (r1 - r2)) {
    cout << "No\n";
    return;
  }

  if (d <= r1 * r1 + 2 * r1 * r2 + r2 * r2)
    cout << "Yes\n";
  else
    cout << "No\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
