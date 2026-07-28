#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int m;
    cin >> m;
    for (int i{}; i < m; ++i) {
        int x, y;
        cin >> x >> y;

        int r1 = min(n - d, d);
        int r2 = max(n - d, d);

        int l1 = d - x;
        int h1 = d + x;

        int l2 = d < n - d ? -d + x : d - x;
        int h2 = d < n - d ? d + x : 2 * n - d - x;

        int l3 = -d + x;
        int h3 = 2 * n - d - x;

        if (x <= r1) {
            if (l1 <= y && y <= h1)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else if (r1 <= x && x <= r2) {
            if (l2 <= y && y <= h2)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else if (x <= n) {
            if (l3 <= y && y <= h3)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else {
            cout << "NO\n";
        }
    }
}
