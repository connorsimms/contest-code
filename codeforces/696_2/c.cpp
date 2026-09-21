#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    map<int, int> M;
    for (int i{}; i < 2 * n; ++i) {
      int x;
      cin >> x;
      ++M[x];
    }

    bool found = false;
    for (auto [o, f] : M) {
      auto m = M;
      auto it = next(end(m), -1);

      vector<pair<int, int>> ans;
      ans.emplace_back(it->first, o);
      auto xi = o + it->first;
      auto x = it->first;

      if (--it->second == 0)
        m.erase(it);

      auto it2 = m.find(o);
      if (it2 == end(m))
        continue;

      if (--it2->second == 0)
        m.erase(it2);

      bool poss = true;

      for (; !m.empty();) {
        auto lit = next(end(m), -1);
        auto lrg = lit->first;
        if (--lit->second == 0)
          m.erase(lit);

        auto oit = m.find(x - lrg);
        if (oit == end(m)) {
          poss = false;
          break;
        }
        auto oth = oit->first;
        if (--oit->second == 0)
          m.erase(oit);

        ans.emplace_back(lrg, oth);

        x = lrg;
      }

      if (poss) {
        found = true;
        cout << "YES\n";
        cout << xi << '\n';
        for (auto &[a, b] : ans) {
          cout << a << ' ' << b << '\n';
        }
        break;
      }
    }

    if (!found) {
      cout << "NO\n";
    }
  }

  return 0;
}
