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

ll binpowmod(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a;
            res %= mod;
        }
        a = a * a;
        a %= mod;
        b >>= 1;
    }
    return res;
}

ll choose_mod(ll a, ll b, ll mod) {
    if (b < 0 || b > a) return 0;

    b = min(b, a - b);

    ll res = 1;
    for (int i = 1; i <= b; ++i) {
        res *= (a - i + 1);
        res %= mod;
        res *= binpowmod(i, mod - 2, mod);
        res %= mod;
    }

    return res;
}

ll fact_mod(ll a, ll mod) {
    ll res = 1;
    for (int i = 1; i <= a; ++i) {
        res *= i;
        res %= mod;
    }
    return res;
}

void gen_case(int TC) {
}

void brute(int TC) {}

void solve(int TC) {
    int n;
    cin >> n;

    V<ll> p(n + 1);

    ll mx = 0;
    int numMx = 0;

    for (int i = 0; i <= n; ++i) {
        cin >> p[i];
        if (i) {
            if (p[i] == mx) ++numMx;
            if (chmax(mx, p[i])) numMx = 1;
        }
    }

    bool poss = true;

    ll req1{}, req2{};

    for (int i = 1; i <= n; ++i) {
        if (p[i] < mx - 1)
            req1 += mx - 1 - p[i];

        if (p[i] < mx)
            req2 += mx - p[i];
    }

    dbg(mx, req1, req2);

    if (req1 > p[0]) {
        cout << 0 << '\n';
        return;
    }

    ll ans = 1;
    constexpr ll MOD = 998244353;

    if (p[0] >= req2) {
        ans *= fact_mod(n, MOD);
        cout << ans << '\n';
        return;
    } else {
        ll numA(numMx), numB{};

        for (int i = 1; i <= n; ++i) {
            if (p[i] == mx)
                continue;
            ++numB;
        }

        dbg(numA, numB);

        ll exc = p[0] - req1; // number of elem promoted to max

        ans *= choose_mod(numB, exc, MOD); // # of ways to choose promotions
        ans %= MOD;
        ans *= fact_mod(numA + exc, MOD); // number of ways to order largest elements
        ans %= MOD;
        ans *= fact_mod(numB - exc, MOD); // number of ways to order smallest
        ans %= MOD;

        cout << ans << '\n';
    }
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
