// clang-format off
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ull = unsigned long long;
using str = string;

template <class T> constexpr T INF = numeric_limits<T>::max() / 2;
template <class T> constexpr T NINF = numeric_limits<T>::min() / 2;

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using PQ = priority_queue<T>;
template <class T> using PQG = priority_queue<T, vector<T>, greater<T>>;
template <class T, class U = T> using P = pair<T, U>;
template <class T> using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T, class U> bool chmax(T &l, const U &r) { return (l < r) ? l = r, 1 : 0;}
template <class T, class U> bool chmin(T &l, const U &r) { return (l > r) ? l = r, 1 : 0;}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll rnd(ll a, ll b) { return std::uniform_int_distribution<ll>(a, b)(rng); }

#ifdef DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#define dbge(x) (x)
#endif

#ifdef LOCAL
#include "test.hpp"
#define RUN_TESTS() run_local_tests(argc, argv, gen, brute, true)
#else
#define RUN_TESTS()
#endif

// clang-format on

void gen_case(int TC) {
    auto n = rnd(1, 5);
    auto m = rnd(1, 5);
    auto r = rnd(1, n);
    auto c = rnd(1, m);

    cout << n << ' ' << m << ' ' << r << ' ' << c << '\n';
}

void brute(int TC) {
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    int ans = 0;
    for (ll mask = 0; mask < (1LL << (n * m)); ++mask) {
        bool allValid = true;
        for (int i = 0; i < n - r + 1; ++i) {
            for (int j = 0; j < m - c + 1; ++j) {
                int res = 0;

                for (int x = i; x < i + r; ++x) {
                    for (int y = j; y < j + c; ++y) {
                        auto z = (mask & (1LL << (x * m + y)));
                        res ^= (z != 0);
                    }
                }
                if (res != 0)
                    allValid = false;
            }
        }

        if (allValid) ++ans;

        // if (allValid) {
        //     for (int i = 0; i < n; ++i) {
        //         for (int j = 0; j < m; ++j) {
        //             cout << ((mask & (1LL << (i * m + j))) != 0) << ' ';
        //         }
        //         cout << '\n';
        //     }
        //     cout << '\n';
        // }
    }

    cout << ans << '\n';
}

void solve(int TC) {
    constexpr ull MOD = 998'244'353;

    ull n, m, r, c;
    cin >> n >> m >> r >> c;

    auto pow = r * c - 1 + (c - 1) * (n - r) + (r - 1) * (m - c);

    ull p = 2ULL;
    ull ans = 1;

    while (pow > 0) {
        if (pow & 1) {
            ans *= p;
            ans %= MOD;
        }
        p *= p;
        p %= MOD;
        pow >>= 1ULL;
    }

    cout << ans << '\n';
}

void gen(int seed) {
    rng.seed(seed);
    int tc = rnd(1, 10);
    cout << tc << '\n';
    for (int i = 1; i <= tc; ++i)
        gen_case(i);
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    RUN_TESTS();

    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; ++i)
        solve(i);
}
