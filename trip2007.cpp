#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n != 0) {
    vector<int> v(n);

    for (int i = 0; i < n; ++i)
      cin >> v[i];

    sort(v.rbegin(), v.rend());

    int mode = 1;
    int last = v[0];
    int freq = 1;

    for (int i = 1; i < n; ++i) {
      if (v[i] == last) {
        ++freq;
      } else {
        last = v[i];
        freq = 1;
      }

      mode = max(mode, freq);
    }

    vector<vector<int>> ans(mode);

    for (int i = 0; i < n; ++i) {
      int r = i % mode;

      ans[r].push_back(v[i]);
    }

    cout << ans.size() << '\n';
    for (const auto &r : ans) {
      for (auto x : r)
        cout << x << ' ';
      cout << '\n';
    }
  }
}
