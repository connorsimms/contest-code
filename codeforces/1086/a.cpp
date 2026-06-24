#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;

    cin >> n;

    vector<int> f(n * n + 1);

    int mx = 0;

    for (int i = 0; i < n * n; ++i) {
        int x;
        cin >> x;
        ++f[x];
        mx = (f[x] > mx ? f[x] : mx);
    }

    if (mx <= n * (n - 1))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
