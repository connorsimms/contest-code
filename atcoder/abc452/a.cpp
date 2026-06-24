#include <bits/stdc++.h>
using namespace std;

int main() {
  set<pair<int, int>> s;
  s.emplace(1, 7);
  s.emplace(3, 3);
  s.emplace(5, 5);
  s.emplace(7, 7);
  s.emplace(9, 9);

  int m, d;
  cin >> m >> d;

  if (s.count({m, d}))
    cout << "Yes\n";
  else
    cout << "No\n";
}
