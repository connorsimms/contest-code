#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n, a, b;
  cin >> n >> a >> b;

  ll ans = 0;

  if (b < a * 3) {
    ans += n / 3 * b;
    n %= 3;
  } else {
    ans += n * a;
    n %= 1;
  }

  ans += min(a * n, b);

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
