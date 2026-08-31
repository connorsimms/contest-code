#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> s;
  size_t best{};

  for (int i{}; i < n; ++i) {
    int x;
    cin >> x;

    auto it = lower_bound(begin(s), end(s), x);

    if (it == end(s))
      s.push_back(x);
    else
      *it = x;

    best = max(best, s.size());
  }

  cout << best << '\n';
}
