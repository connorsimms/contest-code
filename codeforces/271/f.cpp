#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i{}; i < n; ++i) {
        cin >> a[i];
    }

    int sz{1};
    while (sz < n)
        sz <<= 1;
    a.resize(sz, 0);

    vector<tuple<int, int, int>> t(4 * sz);

    auto L = [](int idx) { return (idx << 1); };
    auto R = [](int idx) { return (idx << 1) + 1; };

    auto dbg = [](tuple<int, int, int> t) {
        auto [x, y, z] = t;
        cerr << "(" << to_string(x) << ", " << to_string(y) << ", " << to_string(z) << ")";
    };

    auto fn = [](tuple<int, int, int> ln, tuple<int, int, int> rn) {
        auto res = make_tuple(0, 0, 0);
        auto [lw, lnw, lnl] = ln;
        auto [rw, rnw, rnl] = rn;
        auto &[win, numWin, numLose] = res;

        win = gcd(lw, rw);

        if (!lw) {
            numWin = rnw;
            numLose = lnl + rnl + lnw;
        } else if (!rw) {
            numWin = lnw;
            numLose = lnl + rnl + rnw;
        } else if (lw == rw) {
            numWin = lnw + rnw;
            numLose = lnl + rnl;
        } else if (rw % lw == 0) {
            numWin = lnw;
            numLose = lnl + rnl + rnw;
        } else if (lw % rw == 0) {
            numWin = rnw;
            numLose = lnl + rnl + lnw;
        } else {
            numWin = 0;
            numLose = lnl + rnl + lnw + rnw;
        }

        return res;
    };

    auto build = [&](auto &&rec, int v, int l, int r) -> void {
        if (l == r) {
            auto &[win, numWin, numLose] = t[v];
            if (a[l]) {
                win = a[l];
                numWin = 1;
                numLose = 0;
            }
            return;
        }

        auto m = (l + r) / 2;
        rec(rec, L(v), l, m);
        rec(rec, R(v), m + 1, r);
        t[v] = fn(t[L(v)], t[R(v)]);
    };

    auto query = [&](auto &&rec, int v, int l, int r, int i, int j) -> tuple<int, int, int> {
        if (i > j)
            return make_tuple(0, 0, 0);

        if (l == i && r == j) {
            return t[v];
        }

        auto m = (l + r) / 2;
        return fn(rec(rec, L(v), l, m, i, min(j, m)), rec(rec, R(v), m + 1, r, max(i, m + 1), j));
    };

    build(build, 1, 0, sz - 1);

    int q;
    cin >> q;
    for (int i{}; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        auto [win, numWin, numLose] = query(query, 1, 0, sz - 1, l, r);
        cout << numLose << '\n';
    }
}
