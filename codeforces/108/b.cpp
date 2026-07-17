#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int main() {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    --x, --y;
    int k;
    cin >> k;
    ull ans{};
    for (int i{}; i < k; ++i) {
        ll dx, dy;
        cin >> dx >> dy;

        // 0 <= x + dx * s < n
        // 0 <= y + dy * s < m

        ll s = 1e9 + 1;

        if (dx == 0) {
        } else if (dx > 0)
            s = min(s, (n - 1 - x) / dx);
        else
            s = min(s, -x / dx);

        if (dy == 0) {
        } else if (dy > 0)
            s = min(s, (m - 1 - y) / dy);
        else
            s = min(s, -y / dy);

        ans += s;

        x += dx * s;
        y += dy * s;
    }

    cout << ans << '\n';
}
