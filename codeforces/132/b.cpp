#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, m, k;
    cin >> n;
    vector<ll> x(n);
    for (int i{}; i < n; ++i) cin >> x[i];
    sort(x.begin(), x.end());
    cin >> m;
    vector<ll> y(m);
    for (int i{}; i < m; ++i) cin >> y[i];
    sort(y.begin(), y.end());
    cin >> k;
    vector<ll> z(k);
    for (int i{}; i < k; ++i) cin >> z[i];
    sort(z.begin(), z.end());
    int A, B;
    cin >> A >> B;

    // pi (r1^2-r2^2) * p1 / pi r2^2 * p2 = A / B
    // B * (r1 * r1 - r2 * r2) * p1 = A * r2 * r2 * p2
    // B * p1 * r1 * r1 = (A * p2 + B * p1) * r2 * r2
    // (B * p1 * r1 * r1) / (A * p2 + B * p1) = r2 * r2

    auto r1 = x.back();
    auto p2 = z.front();

    double ans{};

    for (auto p1 : y) {
        ll num = B * p1 * r1 * r1;
        ll den = A * p2 + B * p1;
        double frac = static_cast<double>(num) / den;
        double r2 = sqrt(frac);
        ans = max(ans, r2);
    }

    cout << fixed << setprecision(10) << ans << '\n';
}
