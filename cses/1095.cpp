#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

ll exp(ll b, ll e) {
  ll res{1};
  ll pow{b};
  while (e) {
    if (e & 1) {
      res *= pow;
      res %= MOD;
    }
    pow *= pow;
    pow %= MOD;
    e >>= 1;
  }
  return res % MOD;
}

int main() {
  int n;
  cin >> n;
  for (int i{}; i < n; ++i) {
    ll b, e;
    cin >> b >> e;
    cout << exp(b, e) << '\n';
  }
}
