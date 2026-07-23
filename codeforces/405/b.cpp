#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> p(n + 1);
    vector<ll> s(n + 1, 1);
    vector<ll> e(n + 1);

    iota(p.begin(), p.end(), 0);

    auto find = [&](auto &&rec, ll a) {
        if (a == p[a])
            return a;

        return p[a] = rec(rec, p[a]);
    };

    auto join = [&](ll a, ll b) {
        auto x = find(find, a);
        auto y = find(find, b);

        if (x == y) {
            ++e[x];
        } else {
            p[x] = y;
            s[y] += s[x];
            e[y] += e[x] + 1;
        }
    };

    for (int i{}; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        join(a, b);
    }

    bool valid = true;
    for (int i{1}; i <= n; ++i) {
        if (p[i] == i) {
            if (2 * e[i] != s[i] * (s[i] - 1)) {
                valid = false;
                break;
            }
        }
    }

    cout << (valid ? "YES\n" : "NO\n");
}
