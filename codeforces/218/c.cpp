#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
    string ing("BSC");

    string rcp;
    cin >> rcp;

    vector<ull> n(256), f(256), p(256);
    for (auto i : ing)
        cin >> n[i];
    for (auto i : ing)
        cin >> p[i];
    ull r;
    cin >> r;

    for (auto c : rcp)
        ++f[c];

    ull ans{};
    ull lo{}, hi{1'000'000'000'101ULL};
    while (lo <= hi) {
        auto mid = (lo + hi) / 2;

        ull cost{};
        for (auto i : ing) {
            auto need = n[i] > mid * f[i] ? 0 : mid * f[i] - n[i];
            cost += need * p[i];
        }

        if (cost <= r) {
            ans = max(ans, mid);
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
}
