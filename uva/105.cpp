#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, H, R;

    vector<pair<int, int>> h(10001);

    while (cin >> L >> H >> R) {
        h[L].second = max(h[L].second, H);
        for (int i{L + 1}; i <= R - 1; ++i) {
            h[i].first = max(h[i].first, H);
            h[i].second = max(h[i].second, H);
        }
        h[R].first = max(h[R].first, H);
    }

    int i = 0;

    while (i < h.size() && h[i].first == h[i].second)
        ++i;

    bool first = true;
    while (i < h.size()) {
        if (!first) cout << ' ';
        first = false;

        cout << i << ' ' << h[i].second;

        ++i;
        while (i < h.size() && h[i].first == h[i].second)
            ++i;
    }
    cout << '\n';
}
