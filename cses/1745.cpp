#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> c(n);

  for (int i{}; i < n; ++i)
    cin >> c[i];

  sort(begin(c), end(c));

  vector<bool> poss(100'001);

  for (auto d : c) {
    for (size_t i{poss.size() - 1}; i > 0; --i) {
      if (poss[i])
        poss[i + d] = true;
    }
    poss[d] = true;
  }

  vector<int> ans;
  for (size_t i{}; i < poss.size(); ++i) {
    if (poss[i])
      ans.push_back(i);
  }
  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}
