#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second - a.first == b.second - b.first) {
      return a.first < b.first;
    }
    return a.second - a.first > b.second - b.first;
  };

  set<pair<int, int>, decltype(cmp)> I;
  set<int> L;

  int x;
  cin >> x;
  L.insert(0);
  L.insert(x);
  I.emplace(0, x);

  int n;
  cin >> n;
  for (int i{}; i < n; ++i) {
    int p;
    cin >> p;

    auto ub = L.upper_bound(p);
    auto lb = next(ub, -1);

    auto lp = *lb, rp = *ub;

    I.erase({lp, rp});
    I.emplace(lp, p);
    I.emplace(p, rp);
    L.insert(p);

    auto f = I.begin();
    cout << f->second - f->first << '\n';
  }
}
