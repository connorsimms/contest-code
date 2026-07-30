#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ull n, r, avg;
    cin >> n >> r >> avg;

    vector<pair<ull, ull>> e;
    ull sum{};
    for (ull i{}; i < n; ++i) {
        ull a, b;
        cin >> a >> b;
        sum += a;
        e.emplace_back(b, r - a);
    }

    if (sum >= avg * n) {
        cout << 0 << '\n';
        return 0;
    }

    ull need = avg * n - sum;

    sort(begin(e), end(e));

    ull ans{};
    for (auto [b, pts] : e) {
        if (need <= pts) {
            ans += b * need;
            need = 0;
            break;
        } else {
            need -= pts;
            ans += b * pts;
        }
    }

    cout << ans << '\n';
}
