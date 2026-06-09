#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  vector<bool> isPrime(10'000'001, true);
  isPrime[0] = isPrime[1] = false;
  vector<int> d1(10'000'001);
  vector<int> d2(10'000'001);
  for (ll i = 2; i < isPrime.size(); ++i) {
    if (!isPrime[i])
      continue;

    for (ll j = i * 2; j < isPrime.size(); j += i) {
      isPrime[j] = false;
      if (d1[j] == 0)
        d1[j] = i;
      else if (d2[j] == 0)
        d2[j] = i;
    }
  }

  int n;
  cin >> n;

  vector<pair<int, int>> ans(n, {-1, -1});

  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;

    if (isPrime[a])
      continue;

    if (__builtin_popcount(a) == 1)
      continue;

    if (d1[a] == 0 || d2[a] == 0)
      continue;

    ll x = 1, y = a;
    while (y % d1[a] == 0) {
      x *= d1[a];
      y /= d1[a];
    }

    ans[i].first = x;
    ans[i].second = y;
  }

  for (auto &[d1, d2] : ans)
    cout << d1 << ' ';
  cout << '\n';
  for (auto &[d1, d2] : ans)
    cout << d2 << ' ';
  cout << '\n';
}
