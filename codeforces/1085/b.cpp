#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n, m, l;
  cin >> n >> m >> l;

  deque<int> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int time = 0;
  vector<int> danger(m);
  vector<bool> valid(m, true);

  for (int i = 0; i < m - n - 1; ++i)
    valid[i] = false;

  int mn = -1, mx = -1;
  while (time <= l) {

    if (!a.empty() && a.front() == time) {
      danger[mx] = 0;

      if (a.size() < m) {
        valid[mx] = false;
      }

      a.pop_front();
    }

    if (time == l)
      break;

    mn = -1;
    for (int i = 0; i < m; ++i) {
      if (!valid[i])
        continue;

      if (mn == -1 || danger[i] < danger[mn])
        mn = i;
    }

    ++danger[mn];

    mx = -1;
    for (int i = 0; i < m; ++i) {
      if (!valid[i])
        continue;

      if (mx == -1 || danger[i] > danger[mx])
        mx = i;
    }

    ++time;
  }

  mx = -1;
  for (int i = 0; i < m; ++i) {
    if (valid[i])
      mx = max(mx, danger[i]);
  }

  cout << mx << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--)
    solve();
}
