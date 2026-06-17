#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;

    cin >> n;

    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        pq.emplace(a, i);
    }

    int ans = 0;
    int lim = n;

    while (!pq.empty()) {
        auto [v, i] = pq.top();
        pq.pop();

        if (i >= lim) continue;

        ++ans;
        lim = i;
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
