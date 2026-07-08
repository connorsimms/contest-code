#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int i{}, j{};

  while (i < s.size() && j < t.size()) {
    if (s[i] == t[j])
      ++i;

    ++j;
  }

  cout << i + 1 << '\n';
}
