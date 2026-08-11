#include <bits/stdc++.h>
using namespace std;

int main() {
    double cube;
    while (cin >> cube && cube > 0.0000001) {
        int lo = 0;
        int hi = 1000;
        int a{};
        double ans{};
        while (lo <= hi) {
            auto m = (lo + hi) / 2;
            if (m * m * m <= cube) {
                lo = m + 1;
                a = m;
                ans = a + (cube - a * a * a) / (3 * a * a);
            } else {
                hi = m - 1;
            }
        }

        cout << fixed << setprecision(4) << ans << '\n';
    }
}
