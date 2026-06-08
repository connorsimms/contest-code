#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  unordered_set<string> rev, revSub;

  bool poss = false;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    string rs(s);
    reverse(rs.begin(), rs.end());
    rev.insert(rs);

    string sub = s.substr(0, s.size() - 1);
    reverse(sub.begin(), sub.end());
    revSub.insert(sub);

    if (rev.count(s) || rev.count(s.substr(1)) || revSub.count(s)) {
      poss = true;
    }
  }

  if (poss)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
