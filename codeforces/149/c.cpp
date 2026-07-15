#include <bits/stdc++.h>
using namespace std;

using ll = long long;

array<int, 8> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
array<int, 8> dc = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ll ri, ci, rf, cf;
    cin >> ri >> ci >> rf >> cf;

    int n;
    cin >> n;

    map<int, vector<pair<int, int>>> a;
    for (int i{}; i < n; ++i) {
        int R, lc, rc;
        cin >> R >> lc >> rc;

        auto &v = a[R];

        auto it = find_if(v.begin(), v.end(), [&](const auto &seg) {
            auto x = seg.first;
            auto y = seg.second;
            // ! (rc < x || lc > y)
            return (rc >= x) && (lc <= y);
        });

        if (it != v.end()) {
            auto &x = it->first;
            auto &y = it->second;
            x = (lc < x ? lc : x);
            y = (rc > y ? rc : y);
        } else {
            v.emplace_back(lc, rc);
        }
    }

    map<pair<int, int>, int> dist;
    queue<pair<int, int>> q;
    q.emplace(ri, ci);
    dist.emplace(make_pair(ri, ci), 0);

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i{}; i < 8; ++i) {
            auto nr = r + dr[i];
            auto nc = c + dc[i];

            auto it = a.find(nr);

            if (it != a.end()) {
                auto &v = it->second;

                auto cont_seg = find_if(v.begin(), v.end(), [&](const auto &seg) {
                    return seg.first <= nc && seg.second >= nc;
                });

                if (cont_seg != v.end()) {
                    auto [_, s] = dist.try_emplace(make_pair(nr, nc), dist[{r, c}] + 1);
                    if (s) {
                        q.emplace(nr, nc);
                    }
                }
            }
        }
    }

    auto it = dist.find(make_pair(rf, cf));

    if (it != dist.end()) {
        cout << it->second << '\n';
    } else {
        cout << "-1\n";
    }
}
