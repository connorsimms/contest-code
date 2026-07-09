#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> g(n, vector<char>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> g[i][j];

    bool ans = true;

    int d = 0;

    for (int i = 0; i < n; ++i)
        d |= (1 << (g[i][i] - 'a'));

    for (int i = 0; i < n; ++i)
        d |= (1 << (g[i][n - 1 - i] - 'a'));

    if (__builtin_popcount(d) != 1)
        ans = false;

    int o = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && i != (n - 1 - j))
                o |= (1 << (g[i][j] - 'a'));

    if (__builtin_popcount(o) != 1)
        ans = false;

    if (d == o)
        ans = false;

    cout << (ans ? "YES\n" : "NO\n");
}
