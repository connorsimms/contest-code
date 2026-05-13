#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m && !(n == 0 && m == 0)) {
    vector<int> d(n), k(m);

    for (int i = 0; i < n; ++i)
      cin >> d[i];
    for (int i = 0; i < m; ++i)
      cin >> k[i];

    sort(d.begin(), d.end());
    sort(k.begin(), k.end());

    bool doom = true;
    int ans = 0;

    for (int i{0}, j{0}; i < n && j < m;) {
      if (d[i] <= k[j]) {
        ans += k[j];
        ++i;
        ++j;
      } else {
        ++j;
      }

      if (i == n)
        doom = false;
    }

    if (!doom)
      cout << ans << '\n';
    else
      cout << "Loowater is doomed!\n";
  }
}
