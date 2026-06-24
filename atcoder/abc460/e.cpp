#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

constexpr int MOD = 998244353;

ull gcd(ull x, ull y) {
  if (y > x)
    swap(x, y);
  while (y != 0) {
    ull a = y;
    y = x % y;
    x = a;
  }
  return x;
}

void solve() {
  ull n, m;
  cin >> n >> m;

  ull lo = 1;
  ull hi = 10;
  ull ans = 0;

  while (lo <= n) {
    ull a = hi - 1;
    ull numX = n / (m / gcd(a, m));
    numX %= MOD;
    ull numY = min(n, hi - 1) - lo + 1;
    numY %= MOD;
    ans += numX * numY;
    ans %= MOD;

    lo *= 10;
    hi *= 10;
  }

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
