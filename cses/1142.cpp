#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  size_t n;
  cin >> n;

  vector<ll> h(n);
  for (size_t i{}; i < n; ++i) {
    cin >> h[i];
  }

  stack<pair<size_t, ll>> s;

  ll ans{};

  for (size_t i{}; i < n; ++i) {
    if (s.empty()) {
      s.emplace(i, h[i]);
      ans = max(ans, h[i]);
      continue;
    }

    if (s.top().second > h[i]) {
      pair<size_t, ll> toPlace{};
      while (!s.empty() && s.top().second > h[i]) {
        ans = max<ll>(ans, s.top().second * (i - s.top().first));
        toPlace = {s.top().first, h[i]};
        s.pop();
      }
      s.push(toPlace);
      ans = max<ll>(ans, h[i] * (i - toPlace.first + 1));
      continue;
    }

    if (s.top().second < h[i]) {
      ans = max<ll>(ans, s.top().second * (i - s.top().first + 1));
      s.emplace(i, h[i]);
      ans = max(ans, h[i]);
      continue;
    }

    if (s.top().second == h[i]) {
      ans = max<ll>(ans, h[i] * (i - s.top().first + 1));
      continue;
    }
  }

  while (!s.empty()) {
    ans = max<ll>(ans, s.top().second * (n - s.top().first));
    s.pop();
  }

  cout << ans << '\n';
}
