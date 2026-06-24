#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    if (y == 0) {
        cout << (x % 3 == 0 ? "YES\n" : "NO\n");
    } else if (y > 0) {
        x -= 2 * y;
        cout << (x >= 0 && x % 3 == 0 ? "YES\n" : "NO\n");
    } else if (y < 0) {
        x += 4 * y;
        cout << (x >= 0 && x % 3 == 0 ? "YES\n" : "NO\n");
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
