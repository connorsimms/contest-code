#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> v(2 * n);
    vector<int> z;

    for (int i = 0; i < 2 * n; ++i) {
      cin >> v[i];
      if (v[i] == 0)
        z.push_back(i);
    }

    int ans = 1;

    for (int i = z[0]; i <= z[1];) {
      int l = i;
      int r = i;

      if (i < z[1] && v[i] == v[i + 1]) {
        r = i + 1;
      }

      while (l > 0 && r < 2 * n - 1 && v[l - 1] == v[r + 1]) {
        --l;
        ++r;
      }

      vector<bool> mex(n + 1);

      for (int j = l; j <= r; ++j)
        mex[v[j]] = true;

      for (int j = 0; j < n + 1; ++j) {
        if (!mex[j]) {
          ans = max(ans, j);
          break;
        }
      }

      i = r + 1;
    }

    cout << ans << '\n';
  }
}
