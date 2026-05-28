#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> v(3 * n);

    for (int i = 0, j = n; i < n; ++i) {
      v[i * 3] = i + 1;
      v[i * 3 + 1] = ++j;
      v[i * 3 + 2] = ++j;
    }

    for (auto x : v)
      cout << x << ' ';
    cout << '\n';
  }
}
