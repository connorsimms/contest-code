#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n, k;
  cin >> n >> k;

  int num = (1 << k) + 1;

  int per = num / 3;

  string a, b;
  cin >> a >> b;
  string c(a.size(), '0');
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i])
      c[i] = '1';
  }

  vector<ll> one(3), zro(3);
  for (auto x : a) {
    if (x == '0')
      ++zro[0];
    else
      ++one[0];
  }

  for (auto x : b) {
    if (x == '0')
      ++zro[1];
    else
      ++one[1];
  }

  for (auto x : c) {
    if (x == '0')
      ++zro[2];
    else
      ++one[2];
  }

  ll ans = 0;
  ans += zro[0] * one[0] * (num / 3 + (num % 3 != 0));
  ans += zro[1] * one[1] * (num / 3 + (num % 3 != 0));
  ans += zro[2] * one[2] * (num / 3);

  cout << ans << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
