#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

  int n;
  cin >> n;
  vector<ll> s(n);
  for (int i{}; i < n; ++i)
    cin >> s[i];

  sort(begin(s), end(s));

  int ans{1};
  ll attack = s.back();
  ll defend = 0;
  int defcnt = 0;

  for (int i = n - 2; i >= 0;) {
    if (defend >= attack) {
      attack += defend;
      ans += defcnt;

      defend = 0;
      defcnt = 0;
      continue;
    }

    defend += s[i];
    ++defcnt;
    --i;
  }

  if (defend >= attack) {
    attack += defend;
    ans += defcnt;

    defend = 0;
    defcnt = 0;
  }

  cout << ans << '\n';
}
