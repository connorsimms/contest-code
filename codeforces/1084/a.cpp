#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int mx = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x > mx) {
            ans = 1;
            mx = x;
        } else if (x == mx)
            ++ans;
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
