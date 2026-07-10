#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
    }
    double dist{};
    for (int i = 1; i < n; ++i) {
        auto [x1, y1] = v[i - 1];
        auto [x2, y2] = v[i];
        auto dx = x2 - x1;
        auto dy = y2 - y1;
        auto z = dx * dx + dy * dy;
        dist += sqrt(z);
    }

    dist /= 50.0;

    cout << fixed << setprecision(7) << dist * k << '\n';
}
