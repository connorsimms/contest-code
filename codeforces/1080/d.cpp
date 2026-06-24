#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;

  vector<ll> f(n);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> f[i];
  }

  sum = (f.front() + f.back()) / (n - 1);
  ll sumcpy = sum;

  for (int i = 0; i < n - 1; ++i) {
    ll a = (sum - f[i] + f[i + 1]) / 2;
    cout << a << ' ';
    sum -= 2 * a;
    sumcpy -= a;
  }

  cout << sumcpy << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
