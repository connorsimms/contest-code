#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = numeric_limits<ll>::max();
constexpr ll NINF = numeric_limits<ll>::min();

int main() {
    size_t N;
    cin >> N;

    vector<ll> a(N);
    for (size_t i{}; i < N; ++i)
        cin >> a[i];

    size_t sz{1};
    while (sz < N)
        sz <<= 1;

    auto L = [](int v) { return (v << 1); };
    auto R = [](int v) { return (v << 1) + 1; };

    a.resize(sz, INF);
    vector<ll> t(4 * sz);
    vector<ll> lazy(4 * sz, 0);

    auto build = [&](auto &&rec, int v, int l, int r) -> void {
        if (l == r) {
            t[v] = a[l];
            return;
        }

        auto m = (l + r) / 2;
        rec(rec, L(v), l, m);
        rec(rec, R(v), m + 1, r);
        t[v] = min(t[L(v)], t[R(v)]);
    };

    auto update = [&](auto &&rec, int v, int l, int r, int i, int j, int inc) {
        if (i > j)
            return;

        if (l == i && r == j) {
            t[v] += inc;
            lazy[v] += inc;
            return;
        }

        if (lazy[v]) {
            t[L(v)] += lazy[v];
            lazy[L(v)] += lazy[v];
            t[R(v)] += lazy[v];
            lazy[R(v)] += lazy[v];
            lazy[v] = 0;
        }

        auto m = (l + r) / 2;
        rec(rec, L(v), l, m, i, min(j, m), inc);
        rec(rec, R(v), m + 1, r, max(i, m + 1), j, inc);
        t[v] = min(t[L(v)], t[R(v)]);
    };

    auto query = [&](auto &&rec, int v, int l, int r, int i, int j) -> ll {
        if (i > j)
            return INF;

        if (l == i && r == j) {
            return t[v];
        }

        if (lazy[v]) {
            t[L(v)] += lazy[v];
            lazy[L(v)] += lazy[v];
            t[R(v)] += lazy[v];
            lazy[R(v)] += lazy[v];
            lazy[v] = 0;
        }

        auto m = (l + r) / 2;
        return min(rec(rec, L(v), l, m, i, min(j, m)), rec(rec, R(v), m + 1, r, max(i, m + 1), j));
    };

    build(build, 1, 0, sz - 1);

    int q;
    cin >> q;
    string line;
    getline(cin, line);
    for (int i{}; i < q; ++i) {
        getline(cin, line);
        stringstream ss{line};
        vector<int> inp;
        int x;
        while (ss >> x)
            inp.push_back(x);

        if (inp.size() == 2) {
            if (inp[0] <= inp[1]) {
                cout << query(query, 1, 0, sz - 1, inp[0], inp[1]) << '\n';
            } else {
                cout << min(query(query, 1, 0, sz - 1, inp[0], N - 1),
                            query(query, 1, 0, sz - 1, 0, inp[1]))
                     << '\n';
            }
        } else if (inp.size() == 3) {
            if (inp[0] <= inp[1]) {
                update(update, 1, 0, sz - 1, inp[0], inp[1], inp[2]);
            } else {
                update(update, 1, 0, sz - 1, inp[0], N - 1, inp[2]);
                update(update, 1, 0, sz - 1, 0, inp[1], inp[2]);
            }
        }
    }
}
