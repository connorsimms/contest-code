#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    size_t N;
    cin >> N;

    struct Node {
        ll sum{};
        int lazy{};
        array<ll, 32> count{};
    };

    vector<int> a(N);
    for (size_t i{}; i < N; ++i)
        cin >> a[i];

    size_t sz{1};
    while (sz < N)
        sz <<= 1;

    a.resize(sz, 0);

    auto L = [](int v) { return v << 1; };
    auto R = [](int v) { return (v << 1) + 1; };

    vector<Node> t(4 * sz);

    auto build = [&](auto &&rec, int v, int l, int r) -> void {
        if (l == r) {
            t[v].sum = a[l];
            t[v].lazy = 0;
            for (int i{}; i < 32; ++i) {
                if (a[l] & (1 << i))
                    ++t[v].count[i];
            }
            return;
        }

        auto m = (l + r) / 2;
        rec(rec, L(v), l, m);
        rec(rec, R(v), m + 1, r);

        t[v].sum = t[L(v)].sum + t[R(v)].sum;
        t[v].lazy = 0;
        for (int i{}; i < 32; ++i) {
            t[v].count[i] = t[L(v)].count[i] + t[R(v)].count[i];
        }
    };

    auto apply = [&](int v, int l, int r, int x) {
        if (l > r)
            return;

        for (int b{}; b < 32; ++b) {
            if (x & (1 << b)) {
                t[v].sum -= t[v].count[b] * (1 << b);
                t[v].count[b] = (r - l + 1) - t[v].count[b];
                t[v].sum += t[v].count[b] * (1 << b);
            }
        }
    };

    auto push = [&](int v, int l, int r) {
        auto m = (l + r) / 2;
        apply(L(v), l, m, t[v].lazy);
        t[L(v)].lazy ^= t[v].lazy;
        apply(R(v), m + 1, r, t[v].lazy);
        t[R(v)].lazy ^= t[v].lazy;
        t[v].lazy = 0;
    };

    auto update = [&](auto &&rec, int v, int l, int r, int i, int j, int x) -> void {
        if (i > j)
            return;

        if (l == i && r == j) {
            apply(v, l, r, x);
            t[v].lazy ^= x;
            return;
        }

        push(v, l, r);
        auto m = (l + r) / 2;
        rec(rec, L(v), l, m, i, min(j, m), x);
        rec(rec, R(v), m + 1, r, max(i, m + 1), j, x);

        t[v].sum = t[L(v)].sum + t[R(v)].sum;
        for (int b{}; b < 32; ++b)
            t[v].count[b] = t[L(v)].count[b] + t[R(v)].count[b];
    };

    auto query = [&](auto &&rec, int v, int l, int r, int i, int j) -> ll {
        if (i > j)
            return 0;

        if (l == i && r == j) {
            return t[v].sum;
        }

        push(v, l, r);
        auto m = (l + r) / 2;
        return rec(rec, L(v), l, m, i, min(j, m)) + rec(rec, R(v), m + 1, r, max(i, m + 1), j);
    };

    build(build, 1, 0, sz - 1);

    int q;
    cin >> q;
    for (int i{}; i < q; ++i) {
        int qt;
        cin >> qt;
        if (qt == 1) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << query(query, 1, 0, sz - 1, l, r) << '\n';
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;
            update(update, 1, 0, sz - 1, l, r, x);
        }
    }
}
