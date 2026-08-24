#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N, Q;
  cin >> N >> Q;

  size_t sz{1};
  while (sz < N)
    sz <<= 1;

  vector<int> A(sz);
  for (size_t i{}; i < N; ++i)
    cin >> A[i];

  vector<ll> t(4 * sz);
  vector<pair<ll, ll>> lazy(4 * sz, {0, 0});

  auto L = [](int v) { return (v << 1); };
  auto R = [](int v) { return (v << 1) + 1; };

  auto build = [&](auto &&rec, int v, int l, int r) -> void {
    if (l == r) {
      t[v] = A[l];
      return;
    }

    auto m = (l + r) / 2;
    rec(rec, L(v), l, m);
    rec(rec, R(v), m + 1, r);

    t[v] = t[L(v)] + t[R(v)];
  };

  auto push = [&](int v, int l, int r) {
    auto [assign, increment] = lazy[v];
    auto m = (l + r) / 2;

    if (assign) {
      t[L(v)] = assign * (m - l + 1);
      lazy[L(v)] = make_pair(lazy[v].first, 0);
      t[R(v)] = assign * (r - m);
      lazy[R(v)] = make_pair(lazy[v].first, 0);
    }

    if (increment) {
      t[L(v)] += increment * (m - l + 1);
      lazy[L(v)].second += increment;
      t[R(v)] += increment * (r - m);
      lazy[R(v)].second += increment;
    }

    lazy[v] = {0, 0};
  };

  auto update = [&](auto &&rec, int v, int l, int r, int i, int j,
                    pair<ll, ll> val) -> void {
    if (i > j)
      return;

    if (l == i && r == j) {
      auto [assign, increment] = val;

      if (assign) {
        t[v] = assign * (r - l + 1);
        lazy[v] = val; // overwrites increment to 0
      } else {
        t[v] += increment * (r - l + 1);
        lazy[v].second += increment;
      }

      return;
    }

    push(v, l, r);
    auto m = (l + r) / 2;

    rec(rec, L(v), l, m, i, min(j, m), val);
    rec(rec, R(v), m + 1, r, max(i, m + 1), j, val);
    t[v] = t[L(v)] + t[R(v)];
  };

  auto query = [&](auto &&rec, int v, int l, int r, int i, int j) -> ll {
    if (i > j)
      return 0;

    if (l == i && r == j)
      return t[v];

    push(v, l, r);
    auto m = (l + r) / 2;

    return rec(rec, L(v), l, m, i, min(j, m)) +
           rec(rec, R(v), m + 1, r, max(m + 1, i), j);
  };

  build(build, 1, 0, sz - 1);

  for (size_t i{}; i < Q; ++i) {
    int type;
    cin >> type;
    switch (type) {
    case 1: {
      int a, b, x;
      cin >> a >> b >> x;
      --a, --b;
      update(update, 1, 0, sz - 1, a, b, make_pair(0, x));
      break;
    }
    case 2: {
      int a, b, x;
      cin >> a >> b >> x;
      --a, --b;
      update(update, 1, 0, sz - 1, a, b, make_pair(x, 0));
      break;
    }
    case 3: {
      int a, b;
      cin >> a >> b;
      --a, --b;

      cout << query(query, 1, 0, sz - 1, a, b) << '\n';
      break;
    }
    }
  }
}
