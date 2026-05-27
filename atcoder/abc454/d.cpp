#include <bits/stdc++.h>
using namespace std;

string reduce(const string &s) {
  vector<int> lp(s.size()), rp(s.size());

  lp[0] = (s[0] == '(' ? 1 : 0);
  rp[s.size() - 1] = (s[s.size() - 1] == ')' ? 1 : 0);

  for (int i = 1; i < (int)lp.size(); ++i)
    lp[i] = (s[i] == '(' ? lp[i - 1] + 1 : 0);

  for (int i = (int)rp.size() - 2; i >= 0; --i)
    rp[i] = (s[i] == ')' ? rp[i + 1] + 1 : 0);

  vector<bool> used(s.size());

  for (int i = 1; i + 2 < s.size(); ++i) {
    if (s[i] == s[i + 1] && s[i] == 'x') {
      int l = lp[i - 1];
      int r = rp[i + 2];
      int m = min(l, r);
      for (int j = i - m; j <= i + 1 + m; ++j) {
        if (j == i || j == i + 1)
          continue;
        used[j] = true;
      }

      i = i + 1 + m;
    }
  }

  string res;

  for (size_t i = 0; i < s.size(); ++i) {
    if (!used[i])
      res.push_back(s[i]);
  }

  return res;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    string a, b;
    cin >> a >> b;

    if (reduce(a) == reduce(b))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
