#include <bits/stdc++.h>
using namespace std;

int main() {
    double vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;

    if (vp >= vd) {
        cout << 0 << '\n';
        return 0;
    }

    double ppos = t * vp;
    double dpos = 0.0;
    int ans{};

    while (ppos < c) {
        auto dv = vd - vp;
        auto x = ppos / dv;

        dpos += x * vd;

        ppos += x * vp;

        if (ppos >= c)
            break;

        ++ans;

        auto y = dpos / vd + f;
        ppos = min(c, ppos + y * vp);
        dpos = 0;
    }

    cout << ans << '\n';
}
