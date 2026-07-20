#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    // 1 0 0 1 0 1
    // 1 | 0 0 1 0

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i{}; i < n; ++i) {
        cin >> p[i];
    }

    int l{};
    while (l < n && p[l] != 1)
        ++l;

    int r{n - 1};
    while (r >= 0 && p[r] != 1)
        --r;

    vector<int> z;
    int str{};
    ll ans{1};

    if (r < l)
        ans = 0;

    for (int i{l}; i <= r; ++i) {
        if (p[i] == 0) {
            ++str;
        } else {
            if (str) z.push_back(str);
            str = 0;
        }
    }

    for (auto s : z)
        ans *= s + 1;

    cout << ans << '\n';
}
