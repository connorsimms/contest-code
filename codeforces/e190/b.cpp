#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  string s;
  cin >> s;

  ll ans = 0;

  vector<int> v;

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '4') {
      ++ans;
      continue;
    } else {
      if (s[i] == '2') {
        v.push_back(0);
      } else {
        v.push_back(1);
      }
    }
  }

  vector<int> even(v.size() + 1);
  vector<int> odd(v.size() + 1);

  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == 1)
      ++odd[i + 1];
    odd[i + 1] += odd[i];
  }

  for (int i = v.size() - 1; i >= 0; --i) {
    if (v[i] == 0)
      ++even[i];
    even[i] += even[i + 1];
  }

  int best = v.size();
  for (int i = 0; i < v.size() + 1; ++i) {
    best = min(best, even[i] + odd[i]);
  }

  ans += best;
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
