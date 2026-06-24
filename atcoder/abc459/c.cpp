#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> v(n + 1);
  vector<int> f(1'000'000);
  int h = 0;

  for (int i = 0; i < q; ++i) {
    char t;
    cin >> t;

    if (t == '1') {
      int x;
      cin >> x;

      if (++f[++v[x]] == n)
        ++h;
    } else {
      int y;
      cin >> y;

      cout << f[h + y] << '\n';
    }
  }
}
