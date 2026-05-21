#include <bits/stdc++.h>
using namespace std;

int main() {
  double T;
  cin >> T;
  int N;
  cin >> N;

  auto cmp = [](const auto &a, const auto &b) {
    return a.first / a.second < b.first / b.second;
  };

  using item = pair<double, int>;

  priority_queue<item, vector<item>, decltype(cmp)> pq(cmp);

  double mn = 1e9;

  for (int i = 0; i < N; ++i) {
    double x;
    cin >> x;
    mn = min(mn, x);
    pq.emplace(x, 1);
  }

  int ans = 0;

  while (true) {
    auto [l, c] = pq.top();
    pq.pop();

    if (mn * c / l > T)
      break;

    ++c;
    ++ans;

    mn = min(mn, l / c);

    pq.emplace(l, c);
  }

  cout << ans << '\n';
}
