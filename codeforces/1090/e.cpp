#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i)
      cin >> v[i];

    int mx = 0;

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        mx = max(mx, v[i] ^ v[j]);

    cout << mx << '\n';
  }
}
