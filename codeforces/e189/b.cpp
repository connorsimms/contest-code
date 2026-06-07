#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;

  int l = -1;
  int r = -1;

  if (s.size() == 1) {
    cout << "YES\n";
    return;
  }

  for (int i = 0; i < s.size() - 1; ++i) {
    if (s[i] == s[i + 1]) {
      l = i + 1;
      break;
    }
  }

  for (int i = s.size() - 1; i > 0; --i) {
    if (s[i] == s[i - 1]) {
      r = i;
      break;
    }
  }

  if (l == r) {
    cout << "YES\n";
    return;
  }

  auto sub = s.substr(l, r - l);

  for (int i = 0; i < sub.size() - 1; ++i) {
    if (sub[i] == sub[i + 1]) {
      cout << "NO\n";
      return;
    }
  }

  reverse(sub.begin(), sub.end());

  if (s[l - 1] != sub.front() && s[r] != sub.back()) {
    cout << "YES\n";
    return;
  }

  for (auto &x : sub) {
    if (x == 'a')
      x = 'b';
    else
      x = 'a';
  }

  if (s[l - 1] != sub.front() && s[r] != sub.back()) {
    cout << "YES\n";
    return;
  }

  cout << "NO\n";
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
