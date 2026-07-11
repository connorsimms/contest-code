#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> f(1001);
    int mx{};
    for (int i{}; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, ++f[a[i]]);
    }

    if (mx > n / 2 + (n & 1))
        cout << "NO\n";
    else
        cout << "YES\n";
}
