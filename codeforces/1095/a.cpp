#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 676'767'677;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i)
      cin >> v[i];

    for (int i = 0; i < n - 1; ++i) {
      if (v[i] == 1) {
        v[i] = 0;
      }
    }

    ll ans = 0;
    for (auto x : v) {
      ans += x;
      ans %= MOD;
    }

    cout << ans << '\n';
  }
}
