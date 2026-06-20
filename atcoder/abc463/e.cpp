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
template <class TC> auto operator<<(ostream &os, const TC &v) -> enable_if_t<!is_convertible_v<TC, string_view>, decltype(begin(v), os)> { os << '{'; str sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; } 

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

int rnd(int a, int b) { return (rand() % (b - a + 1)) + a; }

void gen(int seed) {
    srand(seed);
    int tc = rnd(1, 10);
    cout << tc << '\n';
}

void brute(int TC) {}

void solve(int TC) {
    int N, M, Y;
    cin >> N >> M >> Y;

    vector<vector<pair<ll, ll>>> adj(N + 1);

    for (int i = 0; i < M; ++i) {
        ll u, v, T;
        cin >> u >> v >> T;

        adj[u].emplace_back(v, 2 * T);
        adj[v].emplace_back(u, 2 * T);
    }

    for (int i = 1; i <= N; ++i) {
        ll w;
        cin >> w;
        adj[i].emplace_back(0, 2 * w + Y);
        adj[0].emplace_back(i, 2 * w + Y);
    }

    PQG<P<ll, ll>> pq;
    V<ll> ans(N + 1, INF<ll>);
    ans[1] = 0;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [T, u] = pq.top();
        dbg(T, u);
        pq.pop();

        if (T > ans[u]) continue;

        for (auto &[v, t] : adj[u]) {
            if (ans[u] + t >= ans[v]) continue;

            ans[v] = ans[u] + t;

            pq.emplace(ans[v], v);
        }
    }

    for (int i = 2; i <= N; ++i)
        cout << ans[i] / 2 << ' ';
    cout << '\n';
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (argc > 1) {
        string mode(argv[1]);
        if (mode == "brute") {
            int TC = 1;
            for (int i = 1; i <= TC; ++i)
                brute(i);
        } else if (mode == "gen") {
            gen(atoi(argv[2]));
        }
        return 0;
    }

    int TC = 1;
    for (int i = 1; i <= TC; ++i)
        solve(i);
}
