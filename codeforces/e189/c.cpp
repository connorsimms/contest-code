#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<char>> g(2 + 1, vector<char>(n + 1));

    for (int i = 1; i <= 2; ++i)
        for (int j = 1; j <= n; ++j) cin >> g[i][j];

    vector<int> dp(n + 1);
    dp[1] = (g[1][1] != g[2][1]);

    for (int i = 2; i <= n; ++i) {
        dp[i] = min(dp[i - 1] + (g[1][i] != g[2][i]), dp[i - 2] + (g[1][i] != g[1][i - 1]) + (g[2][i] != g[2][i - 1]));
    }

    cout << dp[n] << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
