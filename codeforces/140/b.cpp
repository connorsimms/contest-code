#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i{}; i < n; ++i) cin >> a[i];

    vector<int> l(n + 1), r(n + 1);
    for (int i = 0; i < n; ++i) {
        l[a[i]] = i + 1;
        r[a[i]] = n - i;
    }

    int m;
    cin >> m;

    long long ansl{}, ansr{};
    for (int i{}; i < m; ++i) {
        int q;
        cin >> q;

        ansl += l[q];
        ansr += r[q];
    }

    cout << ansl << ' ' << ansr << '\n';
}
