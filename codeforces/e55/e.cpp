#include <bits/stdc++.h>
using namespace std;

int maxsub(const vector<int> &v) {
  int cur{}, mn{}, ans{};
  for (auto x : v) {
    cur += x;
    mn = min(mn, cur);
    ans = max(ans, cur - mn);
  }
  return ans;
}

int main() {
  int n, c;
  cin >> n >> c;

  vector<int> a(n), cf(n);
  map<int, vector<int>> m;
  for (int i{}; i < n; ++i) {
    cin >> a[i];

    if (a[i] == c)
      ++cf[i];
    else
      m[a[i]].push_back(i);

    if (i)
      cf[i] += cf[i - 1];
  }

  int mx{};
  for (auto [val, ids] : m) {
    int prev{-1};
    vector<int> v;
    for (auto idx : ids) {
      if (prev != -1) {
        auto cnt = cf[idx - 1] - cf[prev];
        v.push_back(-cnt);
      }
      v.push_back(1);
      prev = idx;
    }
    auto cnt = cf[n - 1] - cf[prev];
    v.push_back(-cnt);
    auto y = maxsub(v);
    mx = max(mx, y);
  }

  cout << cf[n - 1] + mx << '\n';
}
