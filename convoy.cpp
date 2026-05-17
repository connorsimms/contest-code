#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  auto cmp = [](const auto &a, const auto &b) {
    if (a.first == b.first)
      return a.second > b.second;
    return a.first > b.first;
  };

  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 decltype(cmp)>
      pq_h(cmp), pq_s(cmp);

  vector<int> v(n);

  for (int i = 0; i < n; ++i)
    cin >> v[i];

  sort(v.begin(), v.end());

  for (int i = 0; i < min(n, k); ++i)
    pq_h.emplace(v[i], v[i]);

  int toTake = n;

  long long ans = 0;

  while (toTake != 0) {
    long long eta1, eta2;
    int t1, t2;

    if (pq_h.empty()) {
      eta1 = numeric_limits<long long>::max();
      t1 = 0;
    } else {
      eta1 = pq_h.top().first;
      t1 = pq_h.top().second;
    }

    if (pq_s.empty()) {
      eta2 = numeric_limits<long long>::max();
      t2 = 0;
    } else {
      eta2 = pq_s.top().first;
      t2 = pq_s.top().second;
    }

    if (eta1 < eta2) {
      pq_h.pop();
      toTake -= min(toTake, 5);
      pq_s.emplace(eta1 + 2 * t1, t1);
      ans = max(eta1, ans);
    } else {
      pq_s.pop();
      toTake -= min(toTake, 4);

      pq_s.emplace(eta2 + 2 * t2, t2);
      ans = max(eta2, ans);
    }
  }

  cout << ans << '\n';
}
