#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<ull> a(n + 1);
    for (int i{1}; i <= n; ++i)
        cin >> a[i];

    vector<tuple<int, int, ull>> ops(m + 1);
    for (int i{1}; i <= m; ++i) {
        auto &[l, r, d] = ops[i];
        cin >> l >> r >> d;
    }

    vector<ll> ft(m + 1);
    for (int i{1}; i <= k; ++i) {
        int l, r;
        cin >> l >> r;

        for (; l <= m; l += l & -l)
            ++ft[l];

        ++r;
        for (; r <= m; r += r & -r)
            --ft[r];
    }

    vector<ull> f(m + 1);
    for (int i{1}; i <= m; ++i) {
        for (int op = i; op > 0; op -= op & -op) {
            f[i] += ft[op];
        }
    }

    vector<ull> v(n + 1);
    for (int i{1}; i <= m; ++i) {
        auto [l, r, d] = ops[i];

        for (int j{l}; j <= n; j += j & -j) {
            v[j] += d * f[i];
        }

        for (int j{r + 1}; j <= n; j += j & -j) {
            v[j] -= d * f[i];
        }
    }

    for (int i{1}; i <= n; ++i) {
        ull sum{};
        for (int j{i}; j > 0; j -= j & -j) {
            sum += v[j];
        }
        cout << a[i] + sum << ' ';
    }
    cout << '\n';
}
