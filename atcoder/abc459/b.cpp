#include <bits/stdc++.h>
using namespace std;

int atoi(char c) {
  if (c >= 'a' && c <= 'c')
    return 2;

  if (c >= 'd' && c <= 'f')
    return 3;

  if (c >= 'g' && c <= 'i')
    return 4;

  if (c >= 'j' && c <= 'l')
    return 5;

  if (c >= 'm' && c <= 'o')
    return 6;

  if (c >= 'p' && c <= 's')
    return 7;

  if (c >= 't' && c <= 'v')
    return 8;

  return 9;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    cout << atoi(s[0]);
  }
  cout << '\n';
}
