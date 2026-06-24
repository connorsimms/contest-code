#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;

  vector<int> h(n);

  for (int i = 0; i < n; ++i)
    cin >> h[i];

  for (int i = 0; i < n; ++i) {
    vector<int> w(n);
    vector<int> lmx(n), rmx(n);

    int mx = 0;
    for (int j = 1; j < n; ++j) {
      int cur = (i + j) % n;
      int wal = (cur + n - 1) % n;

      mx = max(mx, h[wal]);
      lmx[cur] = mx;
    }

    mx = 0;
    for (int j = 1; j < n; ++j) {
      int cur = (i + n - j) % n;
      int wal = cur;

      mx = max(mx, h[wal]);
      rmx[cur] = mx;
    }

    ll ans = 0;
    for (int j = 0; j < n; ++j) {
      if (j == i)
        continue;
      ans += min(lmx[j], rmx[j]);
    }

    cout << ans << ' ';
  }
  cout << '\n';
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--)
    solve();
}
