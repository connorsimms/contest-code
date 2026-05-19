#include <bits/stdc++.h>
using namespace std;

int main() {
  string bef_str, aft_str;

  getline(cin, bef_str);
  getline(cin, aft_str);

  deque<char> bef, aft;

  for (auto x : bef_str)
    bef.push_back(x);

  for (auto x : aft_str)
    aft.push_back(x);

  while (!bef.empty() && !aft.empty() && bef.front() == aft.front()) {
    bef.pop_front();
    aft.pop_front();
  }

  while (!bef.empty() && !aft.empty() && bef.back() == aft.back()) {
    bef.pop_back();
    aft.pop_back();
  }

  cout << aft.size() << '\n';
}
