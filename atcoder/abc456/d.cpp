#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll MOD = 998244353;

int main() {
  string s;
  cin >> s;
  s.push_back('z');
  vector<pair<ll, char>> v;

  int len = 1;
  char c = s[0];
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == s[i - 1]) {
      ++len;
    } else {
      v.emplace_back(len, c);
      len = 1;
      c = s[i];
    }
  }

  ll endA = 0;
  ll endB = 0;
  ll endC = 0;

  for (auto [x, c] : v) {
    switch (c) {
    case 'a':
      endA += endB * x;
      endA %= MOD;
      endA += endC * x;
      endA %= MOD;
      endA += x;
      endA %= MOD;
      break;
    case 'b':
      endB += endA * x;
      endB %= MOD;
      endB += endC * x;
      endB %= MOD;
      endB += x;
      endB %= MOD;
      break;
    case 'c':
      endC += endA * x;
      endC %= MOD;
      endC += endB * x;
      endC %= MOD;
      endC += x;
      endC %= MOD;
      break;
    }
  }

  ll ans = endA;
  ans += endB;
  ans %= MOD;
  ans += endC;
  ans %= MOD;

  cout << ans << '\n';
}
