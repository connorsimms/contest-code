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
}

void brute(int TC) {
    int n;
    cin >> n;

    V<int> a(n), b(n), c(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];

    for (int i = 0; i < n; ++i)
        cin >> c[i];

    // fix i = 0
    auto check = [&](int i, int j, int k) {
        bool res = true;

        for (int x = 0; x < n; ++x) {
            int ai = (i + x) % n;
            int bi = (j + x) % n;
            int ci = (k + x) % n;

            if (a[ai] < b[bi] && b[bi] < c[ci])
                continue;

            res = false;
            break;
        }

        return res;
    };

    ll ans = 0;
    for (int j = 0; j < n; ++j) { // n^3
        for (int k = 0; k < n; ++k) {
            if (check(0, j, k))
                ++ans;
        }
    }

    cout << n * ans << '\n';
}

void solve(int TC) {
    int n;
    cin >> n;

    V<int> a(n), b(n), c(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];

    for (int i = 0; i < n; ++i)
        cin >> c[i];

    auto check = [&](const auto &x, const auto &y, int i, int j) {
        bool res = true;

        for (int z = 0; z < n; ++z) {
            int ai = (i + z) % n;
            int bi = (j + z) % n;

            if (x[ai] < y[bi])
                continue;

            res = false;
            break;
        }

        return res;
    };

    ll numA{}, numC{};

    // fix j = 0
    for (int i = 0; i < n; ++i) {
        if (check(a, b, i, 0)) {
            ++numA;
        }
    }

    // fix j = 0
    for (int k = 0; k < n; ++k) {
        if (check(b, c, 0, k)) {
            ++numC;
        }
    }

    cout << n * numA * numC << '\n';
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
