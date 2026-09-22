#include <bits/stdc++.h>
using namespace std;

int main() {
  using T = pair<int, int>;

  auto cmp = [](const T &A, const T &B) {
    if (A.second == B.second)
      return A.first < B.first;

    return A.second < B.second;
  };

  multiset<int> et;

  size_t n, k;
  cin >> n >> k;

  vector<T> in;
  for (size_t i{}; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    in.emplace_back(l, r);
  }

  sort(begin(in), end(in), cmp);

  int ans{};
  for (auto &[l, r] : in) {
    if (!et.empty()) {
      auto it = et.upper_bound(l);
      if (it != begin(et)) {
        --it;
        et.erase(it);
        et.emplace(r);
        ++ans;
        continue;
      }
    }

    if (et.size() < k) {
      et.insert(r);
      ++ans;
    }
  }

  cout << ans << '\n';
}
