#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main() {
    ull n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    // 1, 2, ... k - 1
    // max: k * (k - 1) / 2

    ull x = ((k % 2 == 0) ? k : k - 1);
    x /= 2;
    x *= ((k % 2 == 0) ? k - 1 : k);

    if (n - 1 > x) {
        cout << "-1\n";
        return 0;
    }

    ull l{1}, r{k - 1};

    ull i{1};
    ull rm{n - 1};

    while (l <= r) {
        auto m = (l + r) / 2;

        auto sum = (m + k - 1) * (k - m) / 2;

        if (sum <= n - 1) {
            i = m;
            rm = n - 1 - sum;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << k - i + (rm != 0) << '\n';
}
