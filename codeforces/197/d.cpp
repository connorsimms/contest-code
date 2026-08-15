#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    auto sz = 1 << N;
    vector<int> a(sz);
    for (int i{}; i < sz; ++i)
        cin >> a[i];

    vector<int> t(4 * sz);

    auto L = [](int i) { return (i << 1); };
    auto R = [](int i) { return (i << 1) + 1; };

    auto build = [&](auto &&rec, int p, int l, int r, bool o) -> void {
        if (l == r) {
            t[p] = a[l];
            return;
        }

        auto m = (l + r) / 2;
        rec(rec, L(p), l, m, !o);
        rec(rec, R(p), m + 1, r, !o);

        if (o)
            t[p] = t[L(p)] | t[R(p)];
        else
            t[p] = t[L(p)] ^ t[R(p)];
    };

    auto update = [&](auto &&rec, int p, int l, int r, int pos, int val, bool o) -> void {
        if (l == r) {
            t[p] = val;
            return;
        }

        auto m = (l + r) / 2;
        if (pos <= m)
            rec(rec, L(p), l, m, pos, val, !o);
        else
            rec(rec, R(p), m + 1, r, pos, val, !o);

        if (o) {
            t[p] = t[L(p)] | t[R(p)];
        } else {
            t[p] = t[L(p)] ^ t[R(p)];
        }
    };

    auto query = [&](auto &&rec, int p, int l, int r, int i, int j, bool o) -> int {
        if (l > r)
            return 0;

        if (l == i && r == j) {
            return t[p];
        }

        auto m = (l + r) / 2;
        if (o) {
            return rec(rec, L(p), l, m, i, min(j, m), !o) |
                   rec(rec, R(p), m + 1, r, max(i, m + 1), r, !o);
        } else {
            return rec(rec, L(p), l, m, i, min(j, m), !o) ^
                   rec(rec, R(p), m + 1, r, max(i, m + 1), r, !o);
        }
    };

    build(build, 1, 0, sz - 1, N & 1);

    for (int i{}; i < M; ++i) {
        int p, b;
        cin >> p >> b;
        update(update, 1, 0, sz - 1, p - 1, b, N & 1);
        cout << query(query, 1, 0, sz - 1, 0, sz - 1, N & 1) << '\n';
    }
}
