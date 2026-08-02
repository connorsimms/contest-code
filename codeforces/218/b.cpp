#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // 15 20
    // 15 10
    // 15 5
    // 5  5
    // div | change
    // 2 -> 1/2
    // 3 -> 1/3
    // 5 -> 1/5

    ll a, b;
    cin >> a >> b;

    vector<int> fa(6), fb(6);

    for (int d : {2, 3, 5}) {
        while (a % d == 0) {
            a /= d;
            ++fa[d];
        }
        while (b % d == 0) {
            b /= d;
            ++fb[d];
        }
    }

    if (a != b) {
        cout << -1 << '\n';
        return 0;
    }

    int ans{};
    for (int d : {2, 3, 5}) {
        ans += abs(fa[d] - fb[d]);
    }

    cout << ans << '\n';
}
