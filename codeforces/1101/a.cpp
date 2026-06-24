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

  sort(v.begin(), v.end());

  int mIdx = v.size() / 2;
  int med = v[mIdx];

  int l = 0;
  for (int i = 0; i < mIdx; ++i)
    if (v[i] != med)
      ++l;

  int r = 0;
  for (int i = v.size() - 1; i > mIdx; --i)
    if (v[i] != med)
      ++r;

  cout << max(l, r) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
