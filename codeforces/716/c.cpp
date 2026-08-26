#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
  // prod = kn + 1
  // prod coprime with kn
  // prod coprime with n
  // suppose prod = kn + a where a,n not coprime
  // n = 12: 1, 5, 7, 11 -> 385 === 1 mod 12 }

  vector<int> ans;
  ll prod = 1;
  int n;
  cin >> n;
  for (int i{1}; i < n; ++i) {
    if (gcd(i, n) == 1) {
      ans.push_back(i);
      prod *= i;
      prod %= n;
    }
  }

  if (prod != 1)
    ans.pop_back();

  cout << ans.size() << '\n';
  bool first = true;
  for (auto x : ans) {
    if (!first)
      cout << ' ';
    first = false;
    cout << x;
  }
  cout << '\n';
}
