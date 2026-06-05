#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    int sum = 0;

    vector<pair<int, int>> d;

    for (int i = 0; i < s.size(); ++i) {
      int x = s[i] - '0';
      sum += x;
      d.emplace_back(x, i);
    }

    sort(d.begin(), d.end(), [](const auto &a, const auto &b) {
      if (a.first == b.first)
        return a.second > b.second;
      return a.first > b.first;
    });

    int ans = 0;

    for (int i = 0; i < d.size() && sum > 9; ++i, ++ans) {
      auto [x, idx] = d[i];

      if (idx == 0)
        sum -= (x - 1);
      else
        sum -= x;
    }

    cout << ans << '\n';
  }
}
