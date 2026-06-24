#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> v(n);
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    v[i].resize(l);
    for (int j = 0; j < l; ++j)
      cin >> v[i][j];
  }

  int x, y;
  cin >> x >> y;

  cout << v[x - 1][y - 1] << '\n';
}
