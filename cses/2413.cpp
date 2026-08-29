#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

int main() {
  vector<ll> one(1e6 + 1), two(1e6 + 1);
  one[1] = two[1] = 1;

  for (int i{2}; i <= 1e6; ++i) {
    one[i] = one[i - 1] * 4 + two[i - 1];
    one[i] %= MOD;
    two[i] = two[i - 1] * 2 + one[i - 1];
    two[i] %= MOD;
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (one[n] + two[n]) % MOD << '\n';
  }
}
