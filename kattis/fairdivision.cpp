#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int p, n;
    cin >> p >> n;
    deque<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      int b;
      cin >> b;
      v.emplace_back(b, i);
    }

    sort(v.begin(), v.end(), [](const auto &A, const auto &B) {
      if (A.first == B.first)
        return A.second > B.second;
      return A.first < B.first;
    });

    vector<int> ans(n);

    while (p && !v.empty()) {
      int pp = p / v.size();
      int re = p % v.size();

      if (!pp) {
        v.erase(v.begin(), v.begin() + v.size() - re);
        continue;
      }

      int zcnt = 0;

      for (auto &[b, i] : v) {
        if (!b)
          ++zcnt;

        int amt = min(pp, b);

        ans[i] += amt;
        p -= amt;
        b -= amt;
      }

      v.erase(v.begin(), v.begin() + zcnt);
    }

    if (p)
      cout << "IMPOSSIBLE";
    else
      for (auto x : ans)
        cout << x << " ";

    cout << '\n';
  }
}
