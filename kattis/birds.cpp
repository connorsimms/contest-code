#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int l, d, n;
  cin >> l >> d >> n;

  vector<int> p(n);
  for (int i = 0; i < n; ++i)
    cin >> p[i];

  sort(p.begin(), p.end());

  vector<int> s;

  int c = 6;

  for (auto x : p) {
    int sz = x - d - c;

    if (sz >= 0)
      s.push_back(sz);

    c = x + d;
  }

  if (c <= l - 6) {
    s.push_back(l - 6 - c);
  }

  int ans = 0;

  for (auto x : s) {
    ans += x / d + 1;
  }

  cout << ans << '\n';
}
