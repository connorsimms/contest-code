#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  map<int, int> f;

  bool ans1 = true;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;

    ++f[x];

    if (f[x] > 1)
      ans1 = false;
  }

  bool ans2 = (static_cast<int>(f.size()) == m);

  cout << (ans1 ? "Yes\n" : "No\n");
  cout << (ans2 ? "Yes\n" : "No\n");
}
