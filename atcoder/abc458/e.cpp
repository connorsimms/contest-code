#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 998244353;

ll binExp(ll a, ll exp) {
  ll res = 1;
  for (ll i = 0; i < 64; ++i) {
    if (exp & (1LL << i)) {
      res *= a;
      res %= MOD;
    }
    a *= a;
    a %= MOD;
  }
  return res;
}

int main() {
  int x1, x2, x3;
  cin >> x1 >> x2 >> x3;

  ll buckets = x2 + 1;
  ll chooseBuckets = 1;
  ll x1Stars = 1;
  ll x3Stars = 1;

  vector<ll> bucketsChoose(buckets + 1, 1); // # of ways to choose i buckets
  vector<ll> x1Choose(buckets + 1, 1);      // no empty
  vector<ll> x3Choose(buckets + 1, 1);      // allow empty

  // b C 0, b C 1, b C 2, ...
  // 1, b, b(b-1)/2
  // 0, 1, 2
  for (int i = 1; i <= buckets; ++i) {
    bucketsChoose[i] *= bucketsChoose[i - 1];
    bucketsChoose[i] %= MOD;
    bucketsChoose[i] *= buckets - (i - 1);
    bucketsChoose[i] %= MOD;
    bucketsChoose[i] *= binExp(i, MOD - 2);
    bucketsChoose[i] %= MOD;
  }

  // (x1-1) C 0, (x1-1) C 1, (x1-1) C 2 ...
  // 1, (x1-1), (x1-1)(x1-2)/2
  // 1, 2
  for (int i = 2; i <= buckets; ++i) {
    x1Choose[i] *= x1Choose[i - 1];
    x1Choose[i] %= MOD;
    x1Choose[i] *= x1 - (i - 1);
    x1Choose[i] %= MOD;
    x1Choose[i] *= binExp(i - 1, MOD - 2);
    x1Choose[i] %= MOD;
  }

  // 1, (x3 + 1) C 1, (x3 + 2) C 2, ...
  // 1, (x3 + 1), (x3 + 2)(x3 + 1)/2
  // 1, 2
  for (int i = 2; i <= buckets; ++i) {
    x3Choose[i] *= x3Choose[i - 1];
    x3Choose[i] %= MOD;
    x3Choose[i] *= x3 + (i - 1);
    x3Choose[i] %= MOD;
    x3Choose[i] *= binExp(i - 1, MOD - 2);
    x3Choose[i] %= MOD;
  }

  ll ans = 0;

  for (ll i = 1; i <= buckets - 1; ++i) { // # of buckets for x1
    ll ways = bucketsChoose[i];
    ways *= x1Choose[i];
    ways %= MOD;
    ways *= x3Choose[buckets - i];
    ways %= MOD;

    ans += ways;
    ans %= MOD;
  }

  cout << ans << '\n';
}
