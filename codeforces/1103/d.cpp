#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  bool poss = false;

  sort(v.begin(), v.end());

  vector<pair<int, int>> s;

  int len = 1;
  for (int i = 1; i < n; ++i) {
    if (v[i] == v[i - 1])
      ++len;
    else {
      s.emplace_back(v[i - 1], len);
      len = 1;
    }
  }
  s.emplace_back(v.back(), len);

  for (int i = s.size() - 1; i >= 0;) {
    auto [val, cnt] = s[i];

    bool any = false;

    int j = i - 1;
    for (; j >= 0; --j) {
      if (val - s[j].first <= k) {
        any = true;
        continue;
      } else {
        break;
      }
    }

    if (cnt % 2 == 0)
      poss = true;

    if (cnt % 2 == 1 && any)
      poss = true;

    i = j;
  }

  if (poss)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
