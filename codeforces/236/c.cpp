#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, p;
    cin >> n >> p;

    vector<pair<int, int>> e;
    vector<vector<bool>> used(n, vector<bool>(n));

    for (int i{}; i < n; ++i) {
        used[i][(i + 1) % n] = true;
        used[i][(i + 2) % n] = true;
        e.emplace_back(i + 1, (i + 1) % n + 1);
        e.emplace_back(i + 1, (i + 2) % n + 1);
    }

    for (int i{}; p && i < n; ++i) {
        for (int j{}; p && j < n; ++j) {
            if (i == j)
                continue;

            if (used[i][j] || used[j][i])
                continue;

            --p;
            used[i][j] = true;
            e.emplace_back(i + 1, j + 1);
        }
    }

    sort(begin(e), end(e));
    for (auto [u, v] : e)
        cout << u << ' ' << v << '\n';
}

int main() {
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}
