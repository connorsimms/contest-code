#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; ++i)
      cin >> a[i];

    for (int i = 0; i < n; ++i)
      cin >> b[i];

    int lo = 2 * n + 1;
    int hi = 0;

    for (int i = 0; i < n; ++i) {
      lo = min(lo, min(a[i], b[i]));
      hi = max(hi, max(a[i], b[i]));
    }

    int best = 0;

    while (lo <= hi) {
      int mid = (lo + hi) / 2;

      deque<int> c(n);

      for (int i = 0; i < n; ++i) {
        c[i] = (a[i] >= mid) + (b[i] >= mid);
      }

      for (int i = 0; i < c.size() - 1; ++i) {
        if (c[i] < 2 && c[i + 1] < 2) {
          c[i] = max(0, c[i] + c[i + 1] - 1);
          c.erase(c.begin() + i + 1);
          --i;
        }
      }

      int num2 = 0;
      int num0 = 0;

      for (int i = 0; i < c.size(); ++i) {
        if (c[i] == 2)
          ++num2;
        if (c[i] == 0)
          ++num0;
      }

      if (num2 > num0) {
        lo = mid + 1;
        best = mid;
      } else {
        hi = mid - 1;
      }
    }

    cout << best << '\n';
  }
}
