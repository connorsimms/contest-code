#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, x;
  cin >> t >> x;

  int save;
  cin >> save;
  cout << 0 << ' ' << save << '\n';
  for (int i = 1; i <= t; ++i) {
    int a;
    cin >> a;

    if (abs(a - save) >= x) {
      save = a;
      cout << i << " " << save << '\n';
    }
  }
}
