#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;

  vector<pair<int, int>> v;

  for (int i = 0; i < N; ++i) {
    int c, t;
    cin >> c >> t;

    v.emplace_back(t, c);
  }

  sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
    if (a.first == b.first)
      return a.second > b.second;
    return a.first < b.first;
  });

  vector<int> mx(T);

  for (auto &[t, c] : v) {
    int mn = mx[t];
    int mn_idx = t;
    for (int j = t; j >= 0; --j) {
      if (mx[j] < mn) {
        mn = mx[j];
        mn_idx = j;
      }
    }

    if (c > mn) {
      mx[mn_idx] = c;
    }
  }

  int ans = 0;

  for (auto c : mx)
    ans += c;

  cout << ans << '\n';
}
