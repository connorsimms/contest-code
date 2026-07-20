#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i{}; i < n; ++i) {
        int x;
        cin >> x;
        v.emplace_back(x, i);
    }

    sort(v.begin(), v.end());

    int cx = v.front().first;
    int px = 0;
    bool valid = true;

    vector<pair<int, int>> ans;

    for (int i{1}; i < n; ++i) {
        auto [prev, prevIdx] = v[i - 1];
        auto [x, idx] = v[i];

        if (x == cx) {
            if (px == 0) {
                px = idx - prevIdx;
            } else {
                if (idx - prevIdx != px)
                    valid = false;
            }
        } else {
            if (valid) {
                ans.emplace_back(cx, px);
            }
            valid = true;
            cx = x;
            px = 0;
        }
    }

    if (valid)
        ans.emplace_back(cx, px);

    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}
