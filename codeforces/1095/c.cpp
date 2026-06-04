#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; ++i)
      cin >> v[i];

    auto check = [&](int mex) {
      vector<int> a, b;
      vector<int> seen(mex);

      for (auto x : v) {
        if (x < mex && !seen[x]) {
          seen[x] = true;
        } else {
          b.push_back(x);
        }
      }

      for (int i = 0; i < mex; ++i) {
        if (!seen[i]) {
          a.push_back(i);
        }
      }

      sort(a.begin(), a.end());
      sort(b.begin(), b.end());

      int i = a.size() - 1;
      int j = b.size() - 1;
      for (; i >= 0 && j >= 0;) {
        if (2 * a[i] < b[j])
          --i, --j;
        else
          break;
      }

      if (i == -1)
        return true;
      else
        return false;
    };

    int l = 0, r = n;

    int ans = 0;

    while (l <= r) {
      int m = (l + r) / 2;

      bool res = check(m);

      if (res) {
        l = m + 1;
        ans = m;
      } else {
        r = m - 1;
      }
    }

    cout << ans << '\n';
  }
}
