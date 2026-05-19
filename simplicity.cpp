#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  unordered_map<char, int> f;

  for (auto x : s)
    ++f[x];

  vector<int> v;

  for (auto [c, n] : f)
    v.push_back(n);

  sort(v.begin(), v.end());

  int ans = 0;

  for (int i = 0; i < max(0, (int)v.size() - 2); ++i)
    ans += v[i];

  cout << ans << '\n';
}
