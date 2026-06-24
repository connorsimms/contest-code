#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i)
      cin >> v[i];

    int ans = 0;

    for (int i = 0; i < n - 1; ++i) {
      int a = v[i];
      int b = v[i + 1];

      int diff = abs(b - a);

      if ((a % diff) == 0 && (b % diff) == 0) {
        ++ans;
      }
    }

    cout << ans << '\n';
  }
}
