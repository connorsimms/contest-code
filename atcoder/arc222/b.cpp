#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <class T> using v = vector<T>;
template <class T, class U> void chmax(T &l, const U &r) { l = l < r ? r : l; }
template <class T, class U> void chmin(T &l, const U &r) { l = l > r ? r : l; }

ll solve(ll a, ll b, ll c) {
    ll ans = 0;

    chmax(ans, min(a, b - 1));
    chmax(ans, min(b, c - 1));
    chmax(ans, min(c, a - 1));
    chmax(ans, min(a - 1, b + c - 1));
    chmax(ans, min(b - 1, a + c - 1));
    chmax(ans, min(c - 1, a + b - 1));

    --a, --b, --c;
    chmax(ans, min((a + b + c) / 2, min(a + b, min(b + c, c + a))));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (!a)
            cout << max<ll>(0, min(b, c - 1) + (b == c)) << '\n';
        else if (!b)
            cout << max<ll>(0, min(c, a - 1) + (c == a)) << '\n';
        else if (!c)
            cout << max<ll>(0, min(a, b - 1) + (a == b)) << '\n';
        else
            cout << max(solve(a, b, c), max(solve(b, c, a), solve(c, a, b))) << '\n';
    }
}
