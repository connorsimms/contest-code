#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ledger(n + 1);
    for (int i{}; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        ledger[a] -= c;
        ledger[b] += c;
    }
    int sum{};
    for (auto x : ledger) {
        // cerr << x << ' ';
        sum += x < 0 ? -x : 0;
    }
    // cerr << endl;

    cout << sum << '\n';
}
