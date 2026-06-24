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

void gen(int seed) {}

void brute(int TC) {}

V<bool> isPrime(400'001, true);
V<V<int>> pd(400'001);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < isPrime.size(); ++i) {
        if (!isPrime[i]) continue;

        pd[i].push_back(i);

        for (int j = i * 2; j < isPrime.size(); j += i) {
            isPrime[j] = false;
            pd[j].push_back(i);
        }
    }
}

V<bool> seen(400'001);

void solve(int TC) {
    fill(seen.begin(), seen.end(), false);

    int n;
    cin >> n;

    ll ans = INF<ll>;

    V<P<ll, ll>> v(n);
    bool even = false;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        if (!(v[i].first & 1)) even = true;
    }

    for (int i = 0; i < n; ++i)
        cin >> v[i].second;

    sort(v.begin(), v.end());

    V<ll> primes;
    for (int i = 0; i < n; ++i) {
        auto [a, b] = v[i];
        for (auto d : pd[a]) {
            if (seen[d]) {
                cout << "0\n";
                return;
            } else {
                seen[d] = true;
                primes.push_back(d);
            }
        }
    }

    rg::sort(primes);

    ll mn1 = INF<ll>, mn2 = INF<ll>;
    for (int i = 0; i < n; ++i) {
        auto [a, b] = v[i];
        if (a & 1) {
            if (b < mn1) {
                mn2 = mn1;
                mn1 = b;
            } else if (b < mn2) {
                mn2 = b;
            }
        }
    }

    if (even) chmin(ans, min(mn1, mn2));
    else chmin(ans, mn1 + mn2);

    for (int i = 0; i < n; ++i) {
        auto [a, b] = v[i];

        if (b >= ans)
            continue;

        if (primes.size() < ans / b) {
            for (auto p : primes) {
                if (a % p)
                    chmin(ans, (p - (a % p)) * b);

                if (p > a)
                    break;
            }
        } else {
            ll cnt = 1;
            bool done = false;
            while (b * cnt < ans && !done && a + cnt <= 400'000) {
                for (auto d : pd[a + cnt]) {
                    if (a % d == 0) continue;

                    if (seen[d]) {
                        chmin(ans, b * cnt);
                        done = true;
                        break;
                    }
                }
                ++cnt;
            }
        }
    }

    cout << ans << '\n';
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    if (argc > 1) {
        string mode(argv[1]);
        if (mode == "brute") {
            int TC;
            cin >> TC;
            for (int i = 1; i <= TC; ++i)
                brute(i);
        } else if (mode == "gen") {
            gen(atoi(argv[2]));
        }
        return 0;
    }

    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; ++i)
        solve(i);
}
