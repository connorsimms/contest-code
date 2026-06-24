#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    bool nd = true;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i && a[i] < a[i - 1]) nd = false;
    }

    if (nd)
        cout << n << '\n';
    else
        cout << 1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
