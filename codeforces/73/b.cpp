#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    constexpr int INF = 1'000'000;

    vector<int> dist(26, INF);

    vector<bool> has(26);

    vector<vector<char>> kb(n, vector<char>(m));

    vector<pair<int, int>> sp;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> kb[i][j];
            if (kb[i][j] == 'S')
                sp.emplace_back(i, j);
            else
                has[kb[i][j] - 'a'] = true;
        }
    }

    for (const auto &[si, sj] : sp) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (kb[i][j] != 'S') {
                    auto di = abs(si - i);
                    auto dj = abs(sj - j);
                    auto d = di * di + dj * dj;
                    auto l = kb[i][j] - 'a';
                    dist[l] = d < dist[l] ? d : dist[l];
                }
            }
        }
    }

    int q;
    cin >> q;
    string s;
    cin >> s;
    bool poss = true;
    int ans{};
    for (auto c : s) {
        if (c >= 'a' && c <= 'z' && !has[c - 'a']) {
            poss = false;
            break;
        }

        if (c >= 'A' && c <= 'Z' && dist[c - 'A'] == INF) {
            poss = false;
            break;
        }

        if (c >= 'A' && c <= 'Z' && dist[c - 'A'] > x * x) {
            ++ans;
        }
    }

    if (poss)
        cout << ans << '\n';
    else
        cout << -1 << '\n';
}
