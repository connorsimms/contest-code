#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  bool pr = false;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'o' && !pr)
      continue;

    pr = true;
    cout << s[i];
  }
  cout << '\n';
}
