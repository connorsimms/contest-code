#include <bits/stdc++.h>
using namespace std;

bool check(int l1, int r1, int l2, int r2, int s, int t) {
  if ((l1 != s && l2 != s) || (r1 != t && r2 != t)) {
    return false;
  }

  if (l1 < s || l2 < s || r1 > t || r2 > t) {
    return false;
  }

  if (r1 + 1 < l2) {
    return false;
  }

  return true;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, int>> v;

  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    v.emplace_back(l, r, i);
  }

  auto cmp1 = [](const auto &a, const auto &b) {
    auto [l1, r1, i1] = a;
    auto [l2, r2, i2] = b;

    if (l1 == l2)
      return r1 > r2;
    return l1 < l2;
  };

  sort(v.begin(), v.end(), cmp1);

  vector<int> earlyR(m);
  int mnR = 1'000'001;
  for (int i = m - 1; i >= 0; --i) {
    earlyR[i] = mnR;
    mnR = min(mnR, get<1>(v[i]));
  }

  auto u(v);

  auto cmp2 = [](const auto &a, const auto &b) {
    auto [l1, r1, i1] = a;
    auto [l2, r2, i2] = b;

    if (r1 == r2)
      return l1 < l2;
    return r1 > r2;
  };

  sort(u.begin(), u.end(), cmp2);

  vector<int> lateL(m);
  int mxL = 0;
  for (int i = 0; i < m; ++i) {
    lateL[i] = mxL;
    mxL = max(mxL, get<0>(u[i]));
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int s, t;
    cin >> s >> t;

    auto it1 = lower_bound(v.begin(), v.end(), tuple{s, t, 0}, cmp1);

    if (it1 == v.end()) {
      cout << "No\n";
      continue;
    }

    auto it2 = lower_bound(u.begin(), u.end(), tuple{s, t, 0}, cmp2);

    if (it2 == u.end()) {
      cout << "No\n";
      continue;
    }

    bool poss = false;

    if (get<2>(*it1) == get<2>(*it2)) {

      if (get<0>(*it1) == s && get<1>(*it1) == t) {
        int idx = it1 - v.begin();
        if (earlyR[idx] <= t) {
          poss = true;
        }
      }

      auto nextR = next(it2);
      if (nextR != u.end()) {
        auto [l1, r1, i1] = *it1;
        auto [l2, r2, i2] = *nextR;
        if (check(l1, r1, l2, r2, s, t))
          poss = true;
      }

      auto nextL = next(it1);
      if (nextL != v.end()) {
        auto [l1, r1, i1] = *nextL;
        auto [l2, r2, i2] = *it2;
        if (check(l1, r1, l2, r2, s, t))
          poss = true;
      }
    } else {
      auto [l1, r1, i1] = *it1;
      auto [l2, r2, i2] = *it2;

      if (check(l1, r1, l2, r2, s, t))
        poss = true;
    }

    if (poss)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
