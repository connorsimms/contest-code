#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;

    int mn = 1'000'000;
    int mx = 0;

    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;

      mn = min(mn, a);
      mx = max(mx, a);
    }

    int mid = (mn + mx) / 2;

    cout << max(abs(mx - mid), abs(mn - mid)) << '\n';
  }
}
