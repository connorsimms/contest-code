#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T> using V = vector<T>;

using T = pair<ll, ll>;

T dp(bool ga, bool sb, bool lz, size_t pos, V<V<V<V<T>>>> &mem, V<ll> const &a,
     V<ll> const &b) {
  if (pos == b.size())
    return make_pair(0, 1);

  if (mem[ga][sb][lz][pos].first != 0 || mem[ga][sb][lz][pos].second != 0)
    return mem[ga][sb][lz][pos];

  for (ll dig{}; dig <= 9; ++dig) {
    if (!ga && dig < a[pos])
      continue;

    if (!sb && dig > b[pos])
      continue;

    bool new_ga = ga || (dig > a[pos]);
    bool new_sb = sb || (dig < b[pos]);
    bool new_lz = lz && (dig == 0);

    ll sum, num;
    tie(sum, num) = dp(new_ga, new_sb, new_lz, pos + 1, mem, a, b);

    mem[ga][sb][lz][pos].first += sum;
    mem[ga][sb][lz][pos].first += dig * num;
    mem[ga][sb][lz][pos].second += num;
  }

  return mem[ga][sb][lz][pos];
}

void solve() {
  string A, B;
  cin >> A >> B;

  V<ll> a, b;
  for (size_t i{}; i < B.size() - A.size(); ++i)
    a.push_back(0);
  for (auto c : A)
    a.push_back(c - '0');
  for (auto c : B)
    b.push_back(c - '0');

  V<V<V<V<T>>>> mem(2, V<V<V<T>>>(2, V<V<T>>(2, V<T>(b.size()))));

  cout << dp(0, 0, 1, 0, mem, a, b).first << '\n';
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
