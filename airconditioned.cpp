#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> m;
  for (int i = 0; i < N; ++i) {
    int l, r;
    cin >> l >> r;
    m.emplace_back(l, r);
  }

  sort(m.begin(), m.end(), [](const auto &a, const auto &b) {
    if (a.first == b.first)
      return a.second > b.second;
    return a.first < b.first;
  });

  int ans = 1;
  auto [L, R] = m[0];

  for (int i = 1; i < N; ++i) {
    auto [l, r] = m[i];

    if (l <= R) {
      L = max(L, l);
      R = min(R, r);
    } else {
      L = l;
      R = r;
      ++ans;
    }
  }

  cout << ans << '\n';
}
