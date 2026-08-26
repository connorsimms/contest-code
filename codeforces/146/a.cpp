#include <iostream>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<bool> a(26, false);
  int cnt{};
  for (auto c : s) {
    if (!a[c - 'a'])
      ++cnt;
    a[c - 'a'] = true;
  }
  if (cnt & 1)
    cout << "IGNORE HIM!\n";
  else
    cout << "CHAT WITH HER!\n";
}
