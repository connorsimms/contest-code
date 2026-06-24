#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;

    int per = d / m + 1;

    int ans = n / per + (n % per != 0);

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
