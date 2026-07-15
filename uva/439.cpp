#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e6;

array<int, 8> dr = {-2, -2, -1, -1, 1, 1, 2, 2};
array<int, 8> dc = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    vector<vector<int>> Dist(64, vector<int>(64, INF));

    for (int R{}; R < 8; ++R) {
        for (int C{}; C < 8; ++C) {
            auto Id = R * 8 + C;

            auto &dist = Dist[Id];

            queue<int> q;
            dist[Id] = 0;
            q.push(Id);

            while (!q.empty()) {
                auto f = q.front();
                q.pop();

                auto r = f / 8;
                auto c = f % 8;

                for (int i{}; i < 8; ++i) {
                    auto nr = r + dr[i];
                    auto nc = c + dc[i];

                    if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8) {
                        auto nid = nr * 8 + nc;
                        if (dist[f] + 1 < dist[nid]) {
                            dist[nid] = dist[f] + 1;
                            q.push(nid);
                        }
                    }
                }
            }
        }
    }

    string a, b;
    while (cin >> a >> b) {
        int ri = a[1] - '1';
        int ci = a[0] - 'a';
        int rf = b[1] - '1';
        int cf = b[0] - 'a';

        auto idi = ri * 8 + ci;
        auto idf = rf * 8 + cf;

        // cerr << Dist[idi][idf] << ' ' << Dist[idf][idi] << endl;

        cout << "To get from " << a << " to " << b << " takes " << Dist[idi][idf] << " knight moves.\n";
    }
}
