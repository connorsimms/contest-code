#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);

    bool poss = true;

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    if (k == 1) {
        for (int i = 0; i < n && poss; ++i)
            if (b[i] != -1 && b[i] != a[i]) poss = false;

        cout << (poss ? "YES\n" : "NO\n");
        return;
    }

    for (int i = 0; i < n - k && poss; ++i) {
        if (a[i] != a[i + k]) {
            if (b[i] != -1 && b[i] != a[i]) poss = false;
            if (b[i + k] != -1 && b[i + k] != a[i + k]) poss = false;
            b[i] = a[i];
            b[i + k] = a[i + k];
        } else {
            if (b[i] != -1 && b[i + k] != -1 && b[i] != b[i + k]) poss = false;
            b[i] = b[i + k] = (b[i] == -1 ? b[i + k] : b[i]);
        }
    }

    if (!poss) {
        cout << "NO\n";
        return;
    }

    for (int i = n - 1; i >= k && poss; --i) {
        if (a[i] != a[i - k]) {
            if (b[i] != -1 && b[i] != a[i]) poss = false;
            if (b[i - k] != -1 && b[i - k] != a[i - k]) poss = false;
            b[i] = a[i];
            b[i - k] = a[i - k];
        } else {
            if (b[i] != -1 && b[i - k] != -1 && b[i] != b[i - k]) poss = false;
            b[i] = b[i - k] = (b[i] == -1 ? b[i - k] : b[i]);
        }
    }

    vector<int> fa(n + 1), fb(n + 1);
    int cnt = 0;
    for (int i = 0; i < k; ++i) {
        ++fa[a[i]];
        if (b[i] == -1)
            ++cnt;
        else
            ++fb[b[i]];
    }

    for (int i = 0; i < k; ++i) {
        if (fb[a[i]] > fa[a[i]] || cnt < fa[a[i]] - fb[a[i]])
            poss = false;
        else {
            cnt -= fa[a[i]] - fb[a[i]];
            fb[a[i]] = fa[a[i]];
        }
    }

    cout << (poss ? "YES\n" : "NO\n");
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
