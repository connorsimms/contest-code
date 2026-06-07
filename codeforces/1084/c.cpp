#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  list<char> l;
  for (auto x : s)
    l.push_back(x);

  for (auto it = l.begin(); it != l.end();) {
    auto cur = it;
    auto nxt = next(it);
    if (nxt != l.end() && *it == *nxt) {
      if (it == l.begin()) {
        advance(it, 2);
      } else {
        advance(it, -1);
      }
      l.erase(nxt);
      l.erase(cur);
    } else {
      advance(it, 1);
    }
  }

  if (l.empty())
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
