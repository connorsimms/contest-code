#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<pair<int, int>> b;
        for (int i{}; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            b.emplace_back(x, y);
        }
        int lx, ly;
        tie(lx, ly) = b[n / 2];
        int ss{}, os{};
        for (auto c : b) {
            int x, y;
            tie(x, y) = c;

            if (x == lx || y == ly)
                continue;

            if (x > lx && y > ly)
                ++ss;
            else if (x < lx && y > ly)
                ++os;
            else if (x > lx && y < ly)
                ++os;
            else if (x < lx && y < ly)
                ++ss;
        }

        cout << ss << ' ' << os << '\n';
    }
}
