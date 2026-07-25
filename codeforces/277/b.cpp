#include <bits/stdc++.h>
using namespace std;
int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> b(M, vector<int>(N));

    for (int i{}; i < M; ++i) {
        for (int j{}; j < N; ++j) {
            cin >> b[i][j];
        }
    }

    vector<vector<int>> a(M, vector<int>(N, -1));

    for (int r{}; r < M; ++r) {
        for (int c{}; c < N; ++c) {
            if (!b[r][c]) {
                for (int i{0}; i < M; ++i)
                    a[i][c] = 0;
                for (int i{0}; i < N; ++i)
                    a[r][i] = 0;
            }
        }
    }

    bool valid = true;

    for (int r{}; valid && r < M; ++r) {
        for (int c{}; valid && c < N; ++c) {
            if (b[r][c]) {
                bool oneRow = true;
                bool oneCol = true;
                for (int i{0}; i < M; ++i)
                    if (!b[i][c]) oneCol = false;
                for (int i{0}; i < N; ++i)
                    if (!b[r][i]) oneRow = false;
                if (!oneRow && !oneCol)
                    valid = false;
                if (oneRow && oneCol)
                    a[r][c] = 1;
            }
        }
    }

    // for (const auto &r : a) {
    //     cerr << '\t';
    //     for (auto c : r)
    //         cerr << c << ' ';
    //     cerr << endl;
    // }
    if (valid) {
        for (int r{}; valid && r < M; ++r) {
            for (int c{}; valid && c < N; ++c) {
                if (b[r][c]) {
                    bool hasOne = false;
                    for (int i{0}; i < M; ++i)
                        if (a[i][c]) hasOne = true;
                    for (int i{0}; i < N; ++i)
                        if (a[r][i]) hasOne = true;
                    if (!hasOne) valid = false;
                }
            }
        }
    }

    if (!valid) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (const auto &r : a) {
            for (auto c : r)
                cout << c << ' ';
            cout << '\n';
        }
    }
}
