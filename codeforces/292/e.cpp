#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N, M;
    cin >> N >> M;

    int sz{1};
    while (sz < N)
        sz <<= 1;

    vector<ull> d = {0};
    for (int i{}; i < N - 1; ++i) {
        int x;
        cin >> x;
        d.push_back(x);
    }
    d.resize(sz, 0);

    ull loop;
    cin >> loop;

    vector<ull> pd(d);
    for (size_t i{1}; i < pd.size(); ++i) {
        pd[i] += pd[i - 1];
    }

    vector<ull> h(N);
    for (int i{}; i < N; ++i)
        cin >> h[i];
    h.resize(sz, 0);

    vector<tuple<ull, ull, ull>> t(4 * sz, make_tuple(0, 0, 0));

    auto L = [](int idx) { return (idx << 1); };
    auto R = [](int idx) { return (idx << 1) + 1; };
    auto build = [&](auto &&rec, int v, int l, int r) -> void {
        if (l == r) {
            t[v] = make_tuple(0, 2 * h[l], 2 * h[l]);
            return;
        }

        auto m = (l + r) / 2;
        rec(rec, L(v), l, m);
        rec(rec, R(v), m + 1, r);

        auto [ansL, maxLL, maxLR] = t[L(v)];
        auto [ansR, maxRL, maxRR] = t[R(v)];
        auto &[ans, maxL, maxR] = t[v];
        auto widthL = pd[m] - pd[l];
        auto widthR = pd[r] - pd[m + 1];
        auto rel = pd[m + 1] - pd[m];

        if (maxLL && maxRR)
            ans = max(ansL, max(ansR, maxLR + maxRL + rel));
        maxL = max(maxRL + rel + widthL, maxLL);
        maxR = max(maxLR + rel + widthR, maxRR);
    };

    auto query = [&](auto &&rec, int v, int l, int r, int i, int j) -> tuple<ull, ull, ull> {
        if (i > j)
            return make_tuple(0, 0, 0);

        if (l >= i && r <= j) {
            return t[v];
        }

        auto m = (l + r) / 2;
        auto [ansL, maxLL, maxLR] = rec(rec, L(v), l, m, i, min(j, m));
        auto [ansR, maxRL, maxRR] = rec(rec, R(v), m + 1, r, max(i, m + 1), j);

        auto res = make_tuple(0ULL, 0ULL, 0ULL);
        auto &[ans, maxL, maxR] = res;

        auto widthL = min(j, m) >= i ? pd[min(j, m)] - pd[i] : 0;
        auto widthR = j >= max(i, m + 1) ? pd[j] - pd[max(i, m + 1)] : 0;
        auto rel = (i <= min(j, m) && max(i, m + 1) <= j) ? pd[max(i, m + 1)] - pd[min(j, m)] : 0;

        ans = max(ansL, max(ansR, maxLR + maxRL + rel));
        maxL = max(maxRL + rel + widthL, maxLL);
        maxR = max(maxLR + rel + widthR, maxRR);

        return res;
    };

    build(build, 1, 0, sz - 1);

    for (int i{}; i < M; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;

        if (l <= r) {
            if (l == 0) {
                auto [ans, maxL, maxR] = query(query, 1, 0, sz - 1, r + 1, N - 1);
                cout << ans << '\n';
            } else if (r == N - 1) {
                auto [ans, maxL, maxR] = query(query, 1, 0, sz - 1, 0, l - 1);
                cout << ans << '\n';
            } else {
                auto [ansL, maxLL, maxLR] = query(query, 1, 0, sz - 1, 0, l - 1);
                auto [ansR, maxRL, maxRR] = query(query, 1, 0, sz - 1, r + 1, N - 1);
                cout << max(ansL, max(ansR, maxRR + maxLL + loop)) << '\n';
            }
        } else {
            auto [ans, maxL, maxR] = query(query, 1, 0, sz - 1, r + 1, l - 1);
            cout << ans << '\n';
        }
    }
}
