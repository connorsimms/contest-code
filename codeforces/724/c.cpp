#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<pair<int, int>, int> r;
    int d{}, k{};
    bool first = true;
    for (int i{}; i < n; ++i) {
      if (!first)
        cout << ' ';
      first = false;

      if (s[i] == 'D')
        ++d;
      else
        ++k;

      auto cd = gcd(d, k);
      auto a = d / cd;
      auto b = k / cd;

      cout << ++r[make_pair(a, b)];
    }

    cout << '\n';
  }
}
