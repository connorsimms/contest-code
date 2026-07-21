#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, xg, yg;
    cin >> n >> xg >> yg;

    set<pair<int, int>> s;

    for (int i{}; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        x -= xg;
        y -= yg;

        if (x == 0) {
            s.emplace(0, 1);
            continue;
        }

        if (y == 0) {
            s.emplace(1, 0);
            continue;
        }

        if (x < 0) {
            x *= -1;
            y *= -1;
        }

        s.emplace(x / gcd(x, y), y / gcd(x, y));
    }

    if (s.empty())
        s.emplace(1, 1);

    cout << s.size() << '\n';
}
