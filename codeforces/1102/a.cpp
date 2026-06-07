#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];

  sort(v.rbegin(), v.rend());

  bool ans = true;
  for (int i = 2; i < v.size() && ans; ++i) {
    if (v[i] != v[i - 2] % v[i - 1])
      ans = false;
  }

  if (ans)
    cout << v[0] << ' ' << v[1] << '\n';
  else
    cout << "-1\n";
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--)
    solve();
}
