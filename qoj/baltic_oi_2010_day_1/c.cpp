#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> e;
  for (int i{}; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    e.emplace_back(x, y);
  }
  sort(begin(e), end(e));

  vector<int> l;
  size_t best{};

  for (auto [x, y] : e) {
    best = max(best, l.size());

    if (l.empty()) {
      l.push_back(y);
      continue;
    }

    auto it = lower_bound(rbegin(l), rend(l), y);

    if (it == rbegin(l)) {
      l.push_back(y);
    } else if (it == rend(l)) {
      l[0] = y;
    } else {
      auto base = it.base();
      *base = y;
    }
  }

  best = max(best, l.size());

  cout << best << '\n';
}
