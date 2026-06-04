#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  long long ans = 0;

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'C') {
      ans += min(i + 1, (int)s.size() - i);
    }
  }

  cout << ans << '\n';
}
