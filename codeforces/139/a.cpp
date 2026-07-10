#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int t;
    cin >> t;

    int ll, rr;
    cin >> ll >> rr;

    t = 7 - t;

    bool poss = true;
    for (int i = 1; i < n; ++i) {
        int msk = 0;

        int l, r;
        cin >> l >> r;

        msk |= (1 << l);
        msk |= (1 << r);
        msk |= (1 << (7 - l));
        msk |= (1 << (7 - r));
        msk |= (1 << t);

        if (__builtin_popcount(msk) < 5)
            poss = false;

        t = __builtin_ctz(((1 << 7) - 2) - msk);

        if (poss)
            cerr << "top must be " << t << '\n';

        t = 7 - t;
    }

    cout << (poss ? "YES\n" : "NO\n");
}
