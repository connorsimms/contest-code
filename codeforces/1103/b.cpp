#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<char> s(n + 1);
  for (int i = 1; i <= n; ++i)
    cin >> s[i];

  bool poss = true;

  for (int i = n - k; i >= 1; --i) {
    if (s[i] == '1' && s[i + k] == '1') {
      s[i] = s[i + k] = '0';
    } else if (s[i] == '0' && s[i + k] == '1') {
      s[i] = '1';
      s[i + k] = '0';
    }
  }

  for (int i = 1; i <= n; ++i)
    if (s[i] != '0')
      poss = false;

  if (poss)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
