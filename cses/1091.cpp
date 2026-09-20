#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  map<int, int> p;
  for (int i{}; i < n; ++i) {
    int x;
    cin >> x;
    ++p[x];
  }

  for (int i{}; i < m; ++i) {
    int b;
    cin >> b;

    auto it = p.upper_bound(b);

    if (it == begin(p)) {
      cout << -1 << '\n';
      continue;
    }

    --it;
    cout << it->first << '\n';
    if (--it->second == 0) {
      p.erase(it);
    }
  }
}
