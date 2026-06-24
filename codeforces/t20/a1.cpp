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

void solve(string run) {
    if (run == "first") {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cout << char('a' + x - 1);
        }
        cout << '\n';
    } else {
        string s;
        cin >> s;
        string del = "";
        cout << s.size() << '\n';
        for (auto c : s) {
            cout << del << c - 'a' + 1;
            del = " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string run;
    cin >> run;
    solve(run);
}
