#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main() {
  int n;
  cin >> n;
  ull k;
  cin >> k;

  vector<ull> a(n);

  ull lo = numeric_limits<ull>::max();

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    lo = min(lo, a[i]);
  }

  ull hi = a[0] + k;

  ull ans = lo;

  while (lo <= hi) {
    ull mid = (lo + hi) / 2;

    int poss = true;

    ull moves = k;

    for (int i = 0; i < n && poss; ++i) {
      ull f = i + 1;

      ull diff = mid > a[i] ? mid - a[i] : 0;

      ull used = diff / f + (diff % f != 0);

      if (moves >= used)
        moves -= used;
      else
        poss = false;
    }

    if (poss) {
      lo = mid + 1;
      ans = mid;
    } else {
      hi = mid - 1;
    }
  }

  cout << ans << '\n';
}
