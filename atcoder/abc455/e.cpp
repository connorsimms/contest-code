#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ll n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> a(n), b(n), c(n);

  for (int i = 0; i < n; ++i) {
    if (i) {
      a[i] += a[i - 1];
      b[i] += b[i - 1];
      c[i] += c[i - 1];
    }

    switch (s[i]) {
    case 'A':
      ++a[i];
      break;
    case 'B':
      ++b[i];
      break;
    case 'C':
      ++c[i];
      break;
    }
  }

  vector<int> ab(n), ac(n), bc(n);
  vector<pair<int, int>> abc;

  for (int i = 0; i < n; ++i) {
    ab[i] = a[i] - b[i];
    ac[i] = a[i] - c[i];
    bc[i] = b[i] - c[i];
    abc.emplace_back(a[i] - b[i], a[i] - c[i]);
  }

  unordered_map<int, long long> abFreq, acFreq, bcFreq;
  map<pair<int, int>, long long> abcFreq;
  ++abFreq[0], ++acFreq[0], ++bcFreq[0];
  ++abcFreq[{0, 0}];

  for (auto x : ab)
    ++abFreq[x];

  for (auto x : ac)
    ++acFreq[x];

  for (auto x : bc)
    ++bcFreq[x];

  for (auto x : abc)
    ++abcFreq[x];

  ll ans = (n * (n + 1)) / 2;

  for (auto [x, f] : abFreq) {
    if (f >= 2)
      ans -= (f * (f - 1)) / 2;
  }

  for (auto [x, f] : acFreq) {
    if (f >= 2)
      ans -= (f * (f - 1)) / 2;
  }

  for (auto [x, f] : bcFreq) {
    if (f >= 2)
      ans -= (f * (f - 1)) / 2;
  }

  for (auto [x, f] : abcFreq) {
    if (f >= 2)
      ans += (f * (f - 1));
  }

  cout << max(ans, 0LL) << '\n';
}

// AABBCC (21) = 4 + ab + bc + ac - 2 * abc
// 122222
// 001222
// 000012
//
// A
// AA
// AAB
// AABB
// AABBC
// AABBCC
//  A
//  AB
//  ABB
//  ABBC
//  ABBCC
//   B
//   BB
//   BBC
//   BBCC
//    B
//    BC
//    BCC
//     C
//     CC
//      C
//
// 121000 7 4 + 3
// 122210 5 4 + 1
// 001210 7 4 + 3
//
// 000001 abc
//
