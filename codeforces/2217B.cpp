#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;

  cin >> t;

  while (t--) {
    int n, k, p;
    cin >> n >> p;

    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }

    cin >> k;
    --k;

    int invL = 0;

    for (int i = k; i > 0; --i)
      if (v[i] != v[i - 1])
        ++invL;

    int invR = 0;

    for (int i = k; i < n - 1; ++i)
      if (v[i] != v[i + 1])
        ++invR;

    int mx = max(invL, invR);

    cout << mx + (mx & 1) << '\n';
  }
}
