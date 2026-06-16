#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cout << min(2, n) << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
