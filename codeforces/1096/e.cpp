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

    int mn = 1'000'000;
    int num = 0;
    int mxNum = 0;
    int remId = -1;

    long long ans = 0;

    for (int i = v.size() - 1; i >= 0; --i) {
      if (v[i] < mn) {
        mn = v[i];
        num = 0;
      } else {
        if (++num > mxNum) {
          mxNum = num;
          remId = i;
        }
        ans += v[i] - mn;
      }
    }

    if (remId != -1)
      ans += mxNum;

    cout << ans << '\n';
  }
}
