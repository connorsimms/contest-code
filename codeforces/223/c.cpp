#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    string s;
    cin >> s;

    ull sz{1};
    while (sz < s.size())
        sz <<= 1;

    s.resize(sz, ' ');
    vector<tuple<int, int, int>> t(4 * sz);

    auto L = [](int idx) { return (idx << 1); };
    auto R = [](int idx) { return (idx << 1) + 1; };

    auto build = [&](auto &&rec, int p, int l, int r) -> void {
        if (l == r) {
            auto &[lb, match, rb] = t[p];
            match = 0;
            lb = s[l] == '(' ? 1 : 0;
            rb = s[l] == ')' ? 1 : 0;
            return;
        }

        auto m = (l + r) / 2;
        rec(rec, L(p), l, m);
        rec(rec, R(p), m + 1, r);

        auto [llb, lm, lrb] = t[L(p)];
        auto [rlb, rm, rrb] = t[R(p)];
        auto &[lb, match, rb] = t[p];
        auto newMatches = min(llb, rrb);
        match = lm + rm + 2 * newMatches;
        llb -= newMatches;
        rrb -= newMatches;
        lb = llb + rlb;
        rb = lrb + rrb;
    };

    auto query = [&](auto &&rec, int p, int l, int r, int i, int j) -> tuple<int, int, int> {
        if (i > j) return make_tuple(0, 0, 0);

        if (l == i && r == j) {
            return t[p];
        }

        auto m = (l + r) / 2;
        auto left = rec(rec, L(p), l, m, i, min(j, m));
        auto right = rec(rec, R(p), m + 1, r, max(i, m + 1), j);

        auto [llb, lm, lrb] = left;
        auto [rlb, rm, rrb] = right;

        auto newMatches = min(llb, rrb);
        auto match = lm + rm + 2 * newMatches;
        llb -= newMatches;
        rrb -= newMatches;
        auto lb = llb + rlb;
        auto rb = lrb + rrb;
        return make_tuple(lb, match, rb);
    };

    build(build, 1, 0, sz - 1);

    int q;
    cin >> q;
    for (int i{}; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        auto [lb, match, rb] = query(query, 1, 0, sz - 1, l, r);
        cout << match << '\n';
    }
}
