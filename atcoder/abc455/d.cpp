#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> par(n + 1);
  for (int i = 1; i <= n; ++i)
    par[i] = -i;

  for (int i = 0; i < q; ++i) {
    int c, p;
    cin >> c >> p;

    par[c] = p;
  }

  vector<int> pile(n + 1);

  auto find_pile = [&](int id, auto &&self) {
    if (pile[id])
      return pile[id];

    if (par[id] < 0)
      return pile[id] = -par[id];

    return self(par[id], self);
  };

  vector<int> pileSize(n + 1);

  for (int i = 1; i <= n; ++i) {
    pile[i] = find_pile(i, find_pile);
    ++pileSize[pile[i]];
  }

  for (int i = 1; i <= n; ++i) {
    cout << pileSize[i] << ' ';
  }
  cout << '\n';
}
