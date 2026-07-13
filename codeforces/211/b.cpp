#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    vector<ll> p(n - k + 1);
    ll run{};
    for (int i = 0; i < k; ++i) {
        run += v[i];
    }

    p[0] = run;
    ll mn{run};
    ll ans{0};

    for (int i = 1; i < p.size(); ++i) {
        run -= v[i - 1];
        run += v[k + i - 1];
        p[i] = run;
        if (p[i] < mn) {
            mn = p[i];
            ans = i;
        }
    }

    // for (int i = 0; i < p.size(); ++i) {
    //     cerr << i + 1 << ": " << p[i] << endl;
    // }

    cout << ans + 1 << '\n';
}
