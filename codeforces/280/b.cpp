#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    int mx{};
    for (int i = 0; i < n - 1; ++i) {
        auto d = a[i + 1] - a[i];
        mx = (mx < d ? d : mx);
    }

    double ans = mx / 2.0;

    if (a.front() > ans)
        ans = a.front();

    if (l - a.back() > ans)
        ans = l - a.back();

    cout << fixed << setprecision(9) << ans << '\n';
}
