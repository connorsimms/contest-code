#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using vec = vector<T>;
template <class T, class U> void chmax(T &l, const U &r) { l = r > l ? r : l; }
template <class T, class U> void chmin(T &l, const U &r) { l = r < l ? r : l; }
template <class T> T INF() { return numeric_limits<T>::max(); }

int rnd(int a, int b) { return a + rand() % (b - a - 1); }

void gen(int seed) { srand(seed); }

void brute() {}

inline int dist(ll x1, ll y1, ll x2, ll y2) { return abs(x1 - x2) + abs(y1 - y2); }

void solve() {
    ll n, Ax, Ay, Bx, By;
    cin >> n >> Ax >> Ay >> Bx >> By;

    vec<pair<ll, ll>> h(n);

    for (int i = 0; i < n; ++i) cin >> h[i].first;
    for (int i = 0; i < n; ++i) cin >> h[i].second;

    sort(h.begin(), h.end());

    vec<tuple<ll, ll, ll>> v;
    v.emplace_back(Ax, Ay, Ay);

    ll mnY = INF<int>(), mxY = -1;
    for (auto [x, y] : h) {
        auto &[xb, y1, y2] = v.back();

        if (xb != x) {
            v.emplace_back(x, y, y);
        } else {
            chmin(y1, y);
            chmax(y2, y);
        }
    }

    v.emplace_back(Bx, By, By);

    ll ans = 0;

    for (auto [x, y1, y2] : v) ans += y2 - y1;

    vector<ll> up(v.size()), dn(v.size());

    up.back() = dn.back() = 0;

    for (int i = v.size() - 2; i >= 0; --i) {
        auto [x1, y1, Y1] = v[i];
        auto [x2, y2, Y2] = v[i + 1];

        up[i] = min(dn[i + 1] + dist(x1, Y1, x2, Y2), up[i + 1] + dist(x1, Y1, x2, y2));
        dn[i] = min(dn[i + 1] + dist(x1, y1, x2, Y2), up[i + 1] + dist(x1, y1, x2, y2));
    }

    ans += min(up[0], dn[0]);

    cout << ans << '\n';
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (argc > 1) {
        string mode = argv[1];
        if (mode == "gen")
            gen(atoi(argv[2]));
        else if (mode == "brute") {
            int TC;
            cin >> TC;
            while (TC--) brute();
        }
        return 0;
    }

    int TC;
    cin >> TC;
    while (TC--) solve();
}
