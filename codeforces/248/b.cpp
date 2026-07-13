#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    vector<ll> s(v);
    sort(s.begin(), s.end());
    vector<ll> pv(n + 1), ps(n + 1);
    for (int i = 1; i <= n; ++i) {
        pv[i] = v[i - 1] + pv[i - 1];
        ps[i] = s[i - 1] + ps[i - 1];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            cout << pv[r] - pv[l - 1] << '\n';
        } else {
            cout << ps[r] - ps[l - 1] << '\n';
        }
    }
}
