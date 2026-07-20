#include <bits/stdc++.h>
using namespace std;

int main() {
    int xa, ya, xb, yb, n;
    cin >> xa >> ya >> xb >> yb >> n;
    vector<tuple<int, int, int>> rads;
    for (int i = 0; i < n; ++i) {
        int x, y, r;
        cin >> x >> y >> r;
        rads.emplace_back(x, y, r);
    }

    int ans{};
    for (int x : {xa, xb}) {
        for (int y{min(ya, yb)}; y <= max(ya, yb); ++y) {
            auto it = find_if(rads.begin(), rads.end(), [=](const auto &rad) -> bool {
                auto [xr, yr, r] = rad;
                if ((x - xr) * (x - xr) + (y - yr) * (y - yr) <= r * r)
                    return true;
                return false;
            });
            if (it == rads.end())
                ++ans;
        }
    }

    for (int y : {ya, yb}) {
        for (int x{min(xa, xb) + 1}; x < max(xa, xb); ++x) {
            auto it = find_if(rads.begin(), rads.end(), [=](const auto &rad) -> bool {
                auto [xr, yr, r] = rad;
                if ((x - xr) * (x - xr) + (y - yr) * (y - yr) <= r * r)
                    return true;
                return false;
            });
            if (it == rads.end())
                ++ans;
        }
    }

    cout << ans << '\n';
}
