#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int L, A;
  while (cin >> L >> A) {
    int lsec = -1;
    int rsec = -1;

    vector<pair<int, char>> a(A);

    int lc = 0;

    for (int i = 0; i < A; ++i) {
      int p;
      char d;
      cin >> p >> d;

      a[i].first = p;
      a[i].second = d;

      if (d == 'L') {
        ++lc;
        if (p > lsec) {
          lsec = p;
        }
      } else {
        if (L - p > rsec) {
          rsec = L - p;
        }
      }
    }

    cout << "The last ant will fall down in " << max(lsec, rsec)
         << " seconds - started at ";

    sort(a.begin(), a.end());

    int l = 0, r = 0;

    int l_idx = lc - 1;
    int r_idx = lc;

    if (lsec > rsec)
      cout << a[l_idx].first;
    else if (lsec < rsec)
      cout << a[r_idx].first;
    else
      cout << a[l_idx].first << " and " << a[r_idx].first;

    cout << ".\n";
  }
}
