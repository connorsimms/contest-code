#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int sum = 0;
    int mx = -68;

    vector<int> v(7);

    for (int i = 0; i < 7; ++i) {
      cin >> v[i];
      sum += v[i];
      mx = max(mx, v[i]);
    }

    cout << 2 * mx - sum << '\n';
  }
}
