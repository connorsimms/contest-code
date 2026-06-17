// clang-format off
#include <bits/stdc++.h>
using namespace std;

#if __cplusplus >= 202002L
namespace rg = std::ranges;
#endif

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

template <class A, class B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <class TC, class T = enable_if_t<!is_same_v<TC, str>, class TC::value_type>> ostream &operator<<(ostream &os, const TC &v) { os << '{'; str sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; } 

void dbg_out() { std::cerr << endl; }
template <class H, class... T> void dbg_out(H h, T... t) { std::cerr << ' ' << h; dbg_out(t...); }

constexpr const char *C_ORG = "\033[38;2;235;176;99m", *C_BLU = "\033[38;2;163;169;206m", *C_RED = "\033[38;2;212;119;102m", *C_RST = "\033[0m";

template <class T> T dbg_exp(const char *func, int line, string_view string, T &&expr) { cerr << C_ORG << "[" << func << ":" << line << "]" << C_RST << " " << C_BLU << "[" << string << "]:" << C_RST << " " << expr << '\n'; return expr; }

#ifdef DEBUG
#define dbg(...) cerr << C_ORG << "[" << __FUNCTION__ << ":" << __LINE__ << "]" << C_RST << " " << C_RED << "[" << #__VA_ARGS__ << "]:" << C_RST, dbg_out(__VA_ARGS__)
#define dbge(x) (dbg_exp(__FUNCTION__, __LINE__, #x, x))
#else
#define dbg(...)
#define dbge(x) (x)
#endif
// clang-format on

void gen(int seed) { srand(seed); }

void brute(int TC) {}

void solve(int TC) {
    int n;

    cin >> n;

    deque<tuple<int, int, int>> pt;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        pt.emplace_back(x, y, i);
    }

    vector<int> kind(n);

    {
        auto ptc = pt;

        sort(ptc.begin(), ptc.end(), [](const auto &a, const auto &b) {
            auto [x1, y1, i1] = a;
            auto [x2, y2, i2] = b;
            return x1 < x2;
        });

        for (int i = n / 2; i < n; ++i) {
            auto [x, y, idx] = ptc[i];
            kind[idx] += 1;
        }
    }

    {
        auto ptc = pt;

        sort(ptc.begin(), ptc.end(), [](const auto &a, const auto &b) {
            auto [x1, y1, i1] = a;
            auto [x2, y2, i2] = b;
            return y1 < y2;
        });

        for (int i = n / 2; i < n; ++i) {
            auto [x, y, idx] = ptc[i];
            kind[idx] += 2;
        }
    }

    ll sum = 0;

    V<deque<int>> v(4);

    for (int i = 0; i < n; ++i)
        v[kind[i]].push_back(i);

    auto match = [&](int k1, int k2) -> bool {
        if (!v[k1].empty() && !v[k2].empty()) {
            auto i1 = v[k1].front();
            auto i2 = v[k2].front();
            v[k1].pop_front();
            v[k2].pop_front();
            auto [x1, y1, j1] = pt[i1];
            auto [x2, y2, j2] = pt[i2];
            sum += abs(x1 - x2) + abs(y1 - y2);
            cout << i1 + 1 << ' ' << i2 + 1 << '\n';
            return true;
        }
        return false;
    };

    for (int k = 0; k < 2; ++k)
        while (match(k, 3 - k)) {}

    for (int k1 = 0; k1 < 4; ++k1)
        for (int k2 = k1 + 1; k2 < 4; ++k2)
            while (match(k1, k2)) {}

    for (int k = 0; k < 4; ++k)
        while (v[k].size() >= 2 && match(k, k)) {}

    dbg(sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; ++i)
        solve(i);
}
