#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int a{}, d{};

  for (auto x : s) {
    if (x == 'A')
      ++a;
    if (x == 'D')
      ++d;
  }

  if (a == d)
    cout << "Friendship\n";
  if (a > d)
    cout << "Anton\n";
  if (a < d)
    cout << "Danik\n";
}
