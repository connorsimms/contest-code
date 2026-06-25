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

void brute(int TC) {}

// 0 = 0 -> 1 ^ 1 = 0
// 3 = 11 -> 10 ^ 01
// 6 = 0110, x = 1011, f(x) = 0110
// 8 = 00100 -> n/a
//     1111
// 10 = 01010 -> 11001 ^ 10011 -> 1010
// 11 = 1011 -> n/a/
//
// 12 = 001100 -> 111011 ^ 110111 -> 001100
void solve(int TC) {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "YES\n";
        return;
    }

    int tz = __builtin_ctz(n);

    string s(tz, '0');

    for (int i = 31 - __builtin_clz(n); i >= 0; --i) {
        if ((1 << i) & n)
            s.push_back('1');
        else
            s.push_back('0');
    }

    dbg(s);

    string r(s);
    reverse(r.begin(), r.end());

    if (s == r) {
        if (s.size() % 2) {
            if (s[s.size() / 2] == '1')
                cout << "NO\n";
            else
                cout << "YES\n";
        } else {
            cout << "YES\n";
        }
    } else {
        cout << "NO\n";
        return;
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
