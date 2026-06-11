#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;
  bool hasOne = false;
  bool hasSS = false;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 67)
      hasSS = true;
  }

  if (hasSS)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
