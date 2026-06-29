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
    int n = rnd(1, 1000);
    int k = rnd(1, 1000);

    cout << n << ' ' << k << '\n';
}

void brute(int TC) {
}

ll choose(ll a, ll b) {
    if (b < 0 || b > a) return 0;
    ll res = 1;
    for (int i = 1; i <= b; ++i) {
        res = res * (a - i + 1) / i;
    }
    return res;
}

void solve(int TC) {
    ll n, k;

    cin >> n >> k;

    ll ans = n;

    for (ll i = 1; i <= min(k, 62LL); ++i) // i moves
    {
        for (ll j = 0; j <= i - 1 && (1LL << j) <= n; ++j) // leftmost bit
        {
            if ((1LL << j) == n) {
                if (j == i - 1)
                    --ans;
                break;
            }

            int bits = i - j - 1;

            ll num = choose(j, bits);

            dbg(i, j, bits);

            ans -= num;
        }
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
