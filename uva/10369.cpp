#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &p, int a) {
    if (p[a] == a)
        return a;
    return p[a] = find(p, p[a]);
}

void join(vector<int> &p, int a, int b) {
    auto A = find(p, a);
    auto B = find(p, b);
    if (A != B) {
        p[A] = B;
    }
}

void solve() {
    int S, P;
    cin >> S >> P;

    int numSets{P};
    vector<int> p(P + 1);
    iota(p.begin(), p.end(), 0);

    vector<pair<int, int>> o;
    for (int i{}; i < P; ++i) {
        int x, y;
        cin >> x >> y;
        o.emplace_back(x, y);
    }
    using item = tuple<int, int, int>;
    priority_queue<item, vector<item>, greater<item>> pq;

    for (int i{}; i < P; ++i) {
        int x1, y1;
        tie(x1, y1) = o[i];
        for (int j{i + 1}; j < P; ++j) {
            int x2, y2;
            tie(x2, y2) = o[j];
            int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            pq.emplace(dist, i, j);
        }
    }

    vector<int> dists;

    while (!pq.empty() && numSets > 1) {
        int dist, i, j;
        tie(dist, i, j) = pq.top();
        auto I = find(p, i);
        auto J = find(p, j);
        if (I != J) {
            join(p, I, J);
            dists.push_back(dist);
            --numSets;
        }
        pq.pop();
    }

    for (int i{}; i < S - 1; ++i)
        dists.pop_back();

    cout << fixed << setprecision(2) << sqrt(dists.back()) << '\n';
}

int main() {
    int TC;
    cin >> TC;
    while (TC--)
        solve();
}
