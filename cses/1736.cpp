#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    size_t N, Q;
    cin >> N >> Q;

    size_t sz{1};
    while (sz < N)
        sz <<= 1;

    vector<int> a(sz);
    for (size_t i{}; i < N; ++i)
        cin >> a[i];

    vector<ll> t(4 * sz);
    vector<tuple<ll, ll>> lazy(4 * sz);

    auto L = [](int v) { return (v << 1); };
    auto R = [](int v) { return (v << 1) + 1; };

    auto build = [&](auto &&rec, int v, int l, int r) -> void {
        if (l == r) {
            t[v] = a[l];
            return;
        }

        auto m = (l + r) / 2;
        rec(rec, L(v), l, m);
        rec(rec, R(v), m + 1, r);

        t[v] = t[L(v)] + t[R(v)];
    };

    auto apply = [&](int v, int l, int r, tuple<ll, ll> as) {
        auto [xi, dx] = as;
        t[v] += (xi + xi + dx * (r - l)) * (r - l + 1) / 2;
        auto &[lxi, ldx] = lazy[v];
        lxi += xi;
        ldx += dx;
    };

    auto push = [&](int v, int l, int r) {
        auto [xi, dx] = lazy[v];
        auto m = (l + r) / 2;
        auto l1 = make_tuple(xi, dx);
        auto l2 = make_tuple(xi + (m + 1 - l) * dx, dx);
        apply(L(v), l, m, l1);
        apply(R(v), m + 1, r, l2);
        lazy[v] = make_tuple(0, 0);
    };

    auto update = [&](auto &&rec, int v, int l, int r, int i, int j, tuple<ll, ll> as) -> void {
        if (i > j)
            return;

        if (l == i && r == j) {
            apply(v, l, r, as);
            return;
        }

        push(v, l, r);

        auto [xi, dx] = as;
        auto m = (l + r) / 2;

        auto li = i, lj = min(j, m), ri = max(i, m + 1), rj = j;

        auto l1 = make_tuple(xi, dx);
        auto l2 = make_tuple(xi + (ri - i) * dx, dx);

        rec(rec, L(v), l, m, i, min(j, m), l1);
        rec(rec, R(v), m + 1, r, max(i, m + 1), j, l2);

        t[v] = t[L(v)] + t[R(v)];
    };

    auto query = [&](auto &&rec, int v, int l, int r, int i, int j) -> ll {
        if (i > j)
            return 0;

        if (l == i && r == j) {
            return t[v];
        }

        push(v, l, r);

        auto m = (l + r) / 2;
        return rec(rec, L(v), l, m, i, min(j, m)) + rec(rec, R(v), m + 1, r, max(i, m + 1), j);
    };

    build(build, 1, 0, sz - 1);

    for (size_t i{}; i < Q; ++i) {
        int x, l, r;
        cin >> x >> l >> r;
        --l, --r;
        if (x == 1) {
            update(update, 1, 0, sz - 1, l, r, make_tuple(1, 1));
        } else {
            cout << query(query, 1, 0, sz - 1, l, r) << '\n';
        }
    }
}
