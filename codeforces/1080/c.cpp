#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  int ans = 0;
  for (int i = 1; i < n - 1; ++i) {

    bool changed = false;
    bool left = (v[i] == v[i - 1]) || (v[i] + v[i - 1] == 7);
    bool right = (v[i] == v[i + 1]) || (v[i] + v[i + 1] == 7);

    for (int j = 1; j <= 6 && left && right; ++j) {
      changed = true;
      v[i] = j;
      left = (v[i] == v[i - 1]) || (v[i] + v[i - 1] == 7);
      right = (v[i] == v[i + 1]) || (v[i] + v[i + 1] == 7);
    }

    if (changed)
      ++ans;
  }

  for (int i = 0; i < n - 1; ++i) {
    bool changed = false;
    bool right = (v[i] == v[i + 1]) || (v[i] + v[i + 1] == 7);

    for (int j = 1; j <= 6 && right; ++j) {
      changed = true;
      v[i] = j;
    }

    if (changed)
      ++ans;
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
