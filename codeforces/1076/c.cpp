#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using vec = vector<T>;
template <class T, class U> void chmax(T &l, const U &r) { l = r > l ? r : l; }
template <class T, class U> void chmin(T &l, const U &r) { l = r < l ? r : l; }

int rnd(int a, int b) { return a + rand() % (b - a - 1); }

void gen(int seed) {
    srand(seed);
    cout << '\n';
}

void brute() {}

void solve() {
    int n, q;
    cin >> n >> q;

    vec<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        chmax(a[i], b);
    }

    vec<ll> mx(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        chmax(mx[i], a[i]);
        if (i < n - 1) chmax(mx[i], mx[i + 1]);
    }

    vec<ll> pf(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pf[i] += mx[i - 1];
        pf[i] += pf[i - 1];
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << pf[r] - pf[l - 1] << ' ';
    }
    cout << '\n';
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (argc > 1) {
        string mode = argv[1];
        if (mode == "gen")
            gen(atoi(argv[2]));
        else if (mode == "brute")
            brute();
        return 0;
    }

    int TC;
    cin >> TC;
    while (TC--) solve();
}
