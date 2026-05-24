#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll MOD = 998244353;

int main() {
  string s;
  cin >> s;

  ll ans = 1;
  ll len = 1;

  for (int i = 1; i < s.size(); ++i) {
    if (s[i] != s[i - 1])
      ++len;
    else
      len = 1;

    ans += len;
    ans %= MOD;
  }

  cout << ans << '\n';
}
