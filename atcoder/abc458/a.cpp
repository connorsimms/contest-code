#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;

  for (int i = n; i < s.size() - n; ++i)
    cout << s[i];
  cout << '\n';
}
