#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<char>> g(4, vector<char>(4));
    for (int i{}; i < 4; ++i)
        for (int j{}; j < 4; ++j)
            cin >> g[i][j];

    bool poss = false;

    for (int i{}; i < 3 && !poss; ++i) {
        for (int j{}; j < 3 && !poss; ++j) {
            int cnt{};
            for (int di{}; di < 2; ++di)
                for (int dj{}; dj < 2; ++dj)
                    cnt += g[i + di][j + dj] == '#';

            if (cnt != 2)
                poss = true;
        }
    }

    cout << (poss ? "YES\n" : "NO\n");
}
