#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> t;

  for (int i{}; i < n; ++i) {
    int h;
    cin >> h;
    auto it = upper_bound(begin(t), end(t), h);
    if (it == end(t)) {
      t.push_back(h);
    } else {
      *it = h;
    }
  }

  cout << t.size() << '\n';
}
