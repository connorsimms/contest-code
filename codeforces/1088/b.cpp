#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bitset<10000000> bs;
vector<ll> prime;

constexpr ll MOD = 676767677;

void sieve(ll limit) {
  bs.set();
  bs[0] = bs[1] = 0;

  for (ll i = 2; i < limit; ++i) {
    if (bs[i]) {
      for (ll j = i * i; j < limit; j += i) {
        bs[j] = 0;
      }
      prime.push_back(i);
    }
  }
}

ll numDiv(ll a) {
  ll res = 1;

  for (auto p : prime) {
    if (p > a)
      break;

    ll cnt = 1;
    while (a % p == 0 && p <= a) {
      ++cnt;
      a /= p;
    }
    res *= cnt;
    res %= MOD;
  }

  return res % MOD;
}

int main() {
  sieve(250'000);
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;

    cout << numDiv(abs(x - y)) << '\n';

    for (int i = 0; i < x; ++i)
      cout << "1 ";
    for (int i = 0; i < y; ++i)
      cout << "-1 ";
    cout << '\n';
  }
}
