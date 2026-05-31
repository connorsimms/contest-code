#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    int l = 0, r = 0;
    for (auto x : s) {
      if (x == '(')
        ++l;
      else
        ++r;
    }

    if (l == r)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
