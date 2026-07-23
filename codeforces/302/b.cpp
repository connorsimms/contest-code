#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int mx = (n / 2 + n % 2) * (n / 2 + n % 2) + (n / 2) * (n / 2);
    if (k <= mx) {
        cout << "YES\n";
        int num{};
        vector<vector<char>> g(n, vector<char>(n, 'S'));
        for (int i{}; i < n && num < k; ++i) {
            for (int j{}; j < n && num < k; ++j) {
                if ((i & 1) && (j & 1)) {
                    g[i][j] = 'L';
                    ++num;
                } else if (!(i & 1) && !(j & 1)) {
                    g[i][j] = 'L';
                    ++num;
                }
            }
        }

        for (auto &r : g) {
            for (auto c : r)
                cout << c;
            cout << '\n';
        }
    } else {
        cout << "NO\n";
    }
}
