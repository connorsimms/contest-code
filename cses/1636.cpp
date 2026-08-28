#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

int main() {
  int n;
  ll x;
  cin >> n >> x;

  vector<ll> c(n);
  vector<ll> mem(x + 1);
  mem[0] = 1;

  for (int i{}; i < n; ++i) {
    cin >> c[i];
  }

  sort(begin(c), end(c));

  for (auto d : c) {
    for (int i{}; i + d <= x; ++i) {
      mem[i + d] += mem[i];
      mem[i + d] %= MOD;
    }
  }

  cout << mem[x] << '\n';
}
