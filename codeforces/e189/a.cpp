#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  ull x, y;
  cin >> x >> y;

  y /= x;
  x /= x;

  if (y - x == 1)
    cout << "No\n";
  else
    cout << "Yes\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
