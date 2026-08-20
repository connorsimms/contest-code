#include <bits/stdc++.h>
using namespace std;

int main() {
    constexpr int INF = 1e9;

    size_t N, M;
    cin >> N >> M;

    size_t sz{1};
    while (sz < N)
        sz <<= 1;

    vector<int> a(N);
    for (size_t i{}; i < N; ++i)
        cin >> a[i];
    a.resize(sz, 0);

    vector<int> t(sz * 4);

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

        t[v] = max(t[L(v)], t[R(v)]);
    };
    auto update = [&](auto &&rec, int v, int l, int r, int p, int val) -> void {
        if (l == r) {
            a[l] = val;
            t[v] = val;
            return;
        }

        auto m = (l + r) / 2;

        if (l <= p && p <= m) {
            rec(rec, L(v), l, m, p, val);
        } else if (m + 1 <= p && p <= r) {
            rec(rec, R(v), m + 1, r, p, val);
        }

        t[v] = max(t[L(v)], t[R(v)]);
    };
    auto query = [&](auto &&rec, int v, int l, int r, int lb) {
        if (l == r) {
            if (t[v] >= lb)
                return l;
            else
                return INF;
        }

        if (t[v] >= lb) {
            auto m = (l + r) / 2;
            if (t[L(v)] >= lb) {
                return rec(rec, L(v), l, m, lb);
            } else {
                return rec(rec, R(v), m + 1, r, lb);
            }
        } else {
            return INF;
        }
    };

    build(build, 1, 0, sz - 1);

    bool first = true;

    for (size_t i{}; i < M; ++i) {
        if (!first)
            cout << ' ';
        first = false;

        int r;
        cin >> r;
        auto res = query(query, 1, 0, sz - 1, r);
        if (res == INF) {
            cout << 0;
            continue;
        }
        cout << res + 1;

        update(update, 1, 0, sz - 1, res, a[res] - r);
    }
    cout << '\n';
}
