#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    v.emplace_back(x, y);
  }

  sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
    if (a.first == b.first)
      return a.second > b.second;
    return a.first < b.first;
  });

  int cnt = 1;
  int h = v.front().second;

  for (int i = 1; i < v.size(); ++i) {
    auto [x, y] = v[i];
    if (y <= h) {
      ++cnt;
      h = y;
    }
  }

  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
