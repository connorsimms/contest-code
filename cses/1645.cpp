#include <bits/stdc++.h>
using namespace std;

int main() {
  size_t n;
  cin >> n;
  vector<int> arr(n);
  for (size_t i{}; i < n; ++i) {
    cin >> arr[i];
  }

  bool first = true;
  stack<pair<size_t, int>> s;

  for (size_t i{}; i < n; ++i) {
    if (!first)
      cout << ' ';
    first = false;

    bool placed = false;
    while (!s.empty()) {
      auto [idx, val] = s.top();

      if (val < arr[i]) {
        cout << idx + 1;
        placed = true;
        break;
      } else {
        s.pop();
      }
    }

    if (!placed) {
      cout << 0;
    }

    s.emplace(i, arr[i]);
  }

  cout << '\n';
  return 0;
}
