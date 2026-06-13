#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  string s;
  cin >> s;
  for (auto x : s) {
    if (x >= '0' && x <= '9')
      cout << x;
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
