#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);

    for (int i = 0; i < n; ++i)
      cin >> a[i];

    for (int i = 0; i < n; ++i)
      cin >> b[i];

    ll amx = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] > b[i]) {
        swap(a[i], b[i]);
      }

      amx = max(amx, a[i]);
      ans += b[i];
    }

    ans += amx;

    cout << ans << '\n';
  }
}
