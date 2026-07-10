#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main() {
    ull l, r;
    cin >> l >> r;

    if (r - l <= 1ULL) {
        cout << -1 << '\n';
        return 0;
    }

    if (r - l == 2ULL) {
        if (std::gcd(l, r) != 1ULL)
            cout << l << ' ' << l + 1 << ' ' << r << '\n';
        else
            cout << -1 << '\n';
        return 0;
    }

    if (l & 1) {
        cout << l + 1 << ' ' << l + 2 << ' ' << l + 3 << '\n';
    } else {
        cout << l << ' ' << l + 1 << ' ' << l + 2 << '\n';
    }
}
