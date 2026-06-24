#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;

  ll exc = 0;
  ll prev;
  cin >> prev;
  cout << prev << ' ';
  for (ll i = 1; i <= n - 1; ++i) {
    ll a;
    cin >> a;
    if (a < prev) {
      ll eu = min(exc, prev - a);
      a += eu;
      exc -= eu;

      if (a < prev) {
        ll tot = a + i * prev;
        prev = tot / (i + 1);
        exc = tot % (i + 1);
      }
    } else {
      exc += a - prev;
    }
    cout << prev << ' ';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
