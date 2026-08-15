#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    size_t sz = 1;
    while (sz < s.size())
        sz <<= 1;
    s.resize(sz, 0);

    vector<int> t(4 * sz, 0);

    auto left = [](int idx) {
        return (idx << 1);
    };

    auto right = [](int idx) {
        return (idx << 1) + 1;
    };

    auto build = [&](auto &&rec, int p, int l, int r) -> void {
        if (l == r) {
            t[p] = s[l] ? (1 << (s[l] - 'a')) : 0;
        } else {
            int m = (l + r) / 2;
            rec(rec, left(p), l, m);
            rec(rec, right(p), m + 1, r);
            t[p] = t[left(p)] | t[right(p)];
        }
    };

    build(build, 1, 0, sz - 1);

    auto query = [&](auto &&rec, int p, int l, int r, int i, int j) -> int {
        if (i > j)
            return 0;
        if (l == i && r == j) {
            return t[p];
        }
        auto m = (l + r) / 2;
        return rec(rec, left(p), l, m, i, min(j, m)) | rec(rec, right(p), m + 1, r, max(i, m + 1), j);
    };

    auto update = [&](auto &&rec, int p, int l, int r, int id, int v) -> void {
        if (l == r) {
            t[p] = v;
        } else {
            auto m = (l + r) / 2;
            if (id <= m) {
                rec(rec, left(p), l, m, id, v);
            } else {
                rec(rec, right(p), m + 1, r, id, v);
            }
            t[p] = t[left(p)] | t[right(p)];
        }
    };

    int n;
    cin >> n;
    for (int i{}; i < n; ++i) {
        int q;
        cin >> q;
        if (q == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            update(update, 1, 0, sz - 1, pos - 1, 1 << (c - 'a'));
        } else {
            int l, r;
            cin >> l >> r;
            cout << __builtin_popcount(query(query, 1, 0, sz - 1, l - 1, r - 1)) << '\n';
        }
    }
}
