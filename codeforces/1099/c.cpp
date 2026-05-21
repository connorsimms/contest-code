#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<pair<int, long long>> pos_cost;
    pos_cost.reserve(n * 100);

    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;

      if (x == 1) {
        pos_cost.emplace_back(1, 0);
        pos_cost.emplace_back(2, 1);
        continue;
      }

      long long ops = 0;

      while (true) {
        pos_cost.emplace_back(x, ops);

        if (x == 1) {
          break;
        } else if (x % 2 == 0) {
          x /= 2;
        } else {
          ++x;
        }
        ++ops;
      }
    }

    sort(pos_cost.begin(), pos_cost.end());

    long long ans = numeric_limits<long long>::max();

    auto [curr, _] = pos_cost[0];
    int curr_count = 0;
    long long curr_cost = 0;

    for (auto [pos, cost] : pos_cost) {
      if (pos == curr) {
        ++curr_count;
        curr_cost += cost;
      } else {
        if (curr_count == n) {
          ans = min(ans, curr_cost);
        }
        curr = pos;
        curr_count = 1;
        curr_cost = cost;
      }
    }

    if (curr_count == n) {
      ans = min(ans, curr_cost);
    }

    cout << ans << '\n';
  }
}
