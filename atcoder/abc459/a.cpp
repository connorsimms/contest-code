#include <bits/stdc++.h>
using namespace std;

int main() {
  string s("HelloWorld\n");
  int x;
  cin >> x;

  for (int i = 0; i < s.size(); ++i) {
    if (i == x - 1)
      continue;
    cout << s[i];
  }
}
