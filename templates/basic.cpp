#include <bits/stdc++.h>
using namespace std;

namespace rg = std::ranges;

using ll = long long;
using ull = unsigned long long;
using str = string;

template <class T> constexpr T INF = numeric_limits<T>::max() / 2;
template <class T> constexpr T NINF = numeric_limits<T>::min() / 2;

template <class T> using V = vector<T>;
template <class T> using PQ = priority_queue<T>;
template <class T> using PQG = priority_queue<T, vector<T>, greater<T>>;
template <class T, class U = T> using P = pair<T, U>;

template <class T, class U> void chmax(T &l, const U &r) { l = l < r ? r : l; }
template <class T, class U> void chmin(T &l, const U &r) { l = l > r ? r : l; }

template <class A, class B> ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

template <class TC, class T = class enable_if<!is_same<TC, std::string>::value, class TC::value_type>::type>
std::ostream &operator<<(std::ostream &os, const TC &v) {
    os << '{';
    std::string sep;
    for (const T &x : v) os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() {
    std::cerr << endl;
}

template <class H, class... T> void dbg_out(H h, T... t) {
    std::cerr << ' ' << h;
    dbg_out(t...);
}

template <class T> T dbg_exp(string_view str, T &&expr) {
    std::cerr << "\033[34m[" << str << "]:\033[0m " << expr << '\n';
    return expr;
}

#ifdef DEBUG
#define dbg(...) cerr << "\033[31m[" << #__VA_ARGS__ << "]:\033[0m", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void gen(int seed) { srand(seed); }

void brute(int TC) {}

void solve(int TC) {}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    V<int> v = {5, 4, 3, 2, 1};

    dbg(v);

    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; ++i) solve(i);
}
