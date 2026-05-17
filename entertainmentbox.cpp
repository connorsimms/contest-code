#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> v;

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    v.emplace_back(x, y);
  }

  sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
    if (a.second == b.second)
      return a.first > b.first;
    return a.second < b.second;
  });

  int ans = 0;

  multiset<int> s;
  s.insert(0);

  for (auto &[x, y] : v) {
    auto it = s.upper_bound(x);

    if (it == s.begin()) {
      if (s.size() < k) {
        s.insert(y);
        ++ans;
      }
      continue;
    }

    --it;
    s.erase(it);

    ++ans;
    s.insert(y);
  }

  cout << ans << '\n';
}
