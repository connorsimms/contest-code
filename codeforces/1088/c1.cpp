#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);

    vector<bool> seen(n + 1);

    bool poss = true;

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int i = 0; i < n - k && poss; ++i) {
        if (b[i] != -1) {
            if (b[i] != a[i]) poss = false;
        } else
            b[i] = a[i];
    }

    for (int i = n - 1; i >= k && poss; --i) {
        if (b[i] != -1) {
            if (b[i] != a[i]) poss = false;
        } else
            b[i] = a[i];
    }

    vector<bool> middleA(n + 1);
    for (int i = n - k; i < k; ++i) { middleA[a[i]] = true; }
    for (int i = n - k; i < k; ++i) {
        if (b[i] != -1 && !middleA[b[i]]) poss = false;
    }

    vector<bool> seenB(n + 1);
    for (auto x : b) {
        if (x != -1) {
            if (seenB[x])
                poss = false;
            else
                seenB[x] = true;
        }
    }

    if (poss)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
