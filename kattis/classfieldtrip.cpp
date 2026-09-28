#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;

  string c;

  int i{}, j{};
  for (; i < a.size() && j < b.size();) {
    if (a[i] < b[j]) {
      c.push_back(a[i]);
      ++i;
    } else {
      c.push_back(b[j]);
      ++j;
    }
  }

  while (i < a.size()) {
    c.push_back(a[i]);
    ++i;
  }

  while (j < b.size()) {
    c.push_back(b[j]);
    ++j;
  }

  cout << c << '\n';
}
