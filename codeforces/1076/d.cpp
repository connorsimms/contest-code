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

    int tc = rnd(1, 5);
    cout << tc << '\n';

    while (tc--) {
        int n = rnd(1, 100);
        cout << n << '\n';

        for (int i = 0; i < n; ++i) { cout << rnd(1, 100000) << ' '; }
        for (int i = 0; i < n; ++i) { cout << rnd(1, 100000) << ' '; }

        cout << '\n';
    }
}

void brute() {
    ll n;
    cin >> n;

    vec<ll> a(n), b(n);

    for (int i = 0; i < n; ++i) { cin >> a[i]; }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int i = 1; i < n; ++i) b[i] += b[i - 1];

    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        ll diff = a[i];
        ll num = 0;

        for (int j = i; j < n && a[j] >= diff; ++j) ++num;

        for (int j = 0; j < n; ++j) {
            if (num >= b[j]) chmax(ans, (j + 1) * diff);
        }
    }

    cout << ans << '\n';
}

void solve() {
    ll n;
    cin >> n;

    vec<ll> a(n), b(n);

    for (int i = 0; i < n; ++i) { cin >> a[i]; }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int i = 1; i < n; ++i) b[i] += b[i - 1];

    ll ans = 0;
    ll num = n;
    ll same = 0;

    for (ll i = 0, j = n - 1; i < n && j >= 0;) {
        if (i < n - 1 && a[i] == a[i + 1]) {
            ++same;
            ++i;
            continue;
        }

        ll num = n - i + same;

        auto str = a[i];

        while (j >= 0 && b[j] > num) { --j; }

        if (j >= 0 && b[j] <= num) { chmax(ans, (j + 1) * str); }

        ++i;
        same = 0;
    }

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
