#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> c;
    for (int i{}; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        c.emplace_back(b, a);
    }

    sort(c.rbegin(), c.rend());

    long long rem{n};
    long long ans{};

    for (int i = 0; i < m && rem; ++i) {
        auto [b, a] = c[i];

        auto box = min(rem, a);

        rem -= box;

        ans += box * b;
    }

    cout << ans << '\n';
}
