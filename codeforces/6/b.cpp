#include <bits/stdc++.h>
using namespace std;

array<int, 4> dr{-1, 1, 0, 0};
array<int, 4> dc{0, 0, -1, 1};

int main() {
    int n, m;
    cin >> n >> m;
    char p;
    cin >> p;
    vector<vector<char>> g(n, vector<char>(m));
    for (int i{}; i < n; ++i) {
        for (int j{}; j < m; ++j) {
            cin >> g[i][j];
        }
    }

    int msk{};
    for (int i{}; i < n; ++i) {
        for (int j{}; j < m; ++j) {
            if (g[i][j] == p) {
                for (int k = 0; k < 4; ++k) {
                    auto nr = i + dr[k];
                    auto nc = j + dc[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        if (g[nr][nc] != '.' && g[nr][nc] != p) {
                            auto b = g[nr][nc] - 'A';
                            msk |= (1 << b);
                        }
                    }
                }
            }
        }
    }

    cout << __builtin_popcount(msk) << '\n';
}
