#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  vector<pair<ll, ll>> app(n);

  for (ll i{}; i < n; ++i) {
    ll x;
    cin >> x;
    app[i].first = x - k;
    app[i].second = x + k;
  }

  vector<ll> apt(m);

  for (ll i{}; i < m; ++i) {
    cin >> apt[i];
  }

  sort(begin(apt), end(apt));

  sort(begin(app), end(app),
       [](const pair<ll, ll> &a, const pair<ll, ll> &b) -> bool {
         return a.second < b.second;
       });

  int ans = 0;

  for (size_t i{}, j{}; i < app.size() && j < apt.size();) {
    auto [l, r] = app[i];
    if (l <= apt[j] && apt[j] <= r)
      ++ans, ++i, ++j;
    else if (apt[j] < l)
      ++j;
    else if (apt[j] > r)
      ++i;
  }

  cout << ans << '\n';
}
