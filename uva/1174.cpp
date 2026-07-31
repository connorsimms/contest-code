#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &p, int a) {
    if (p[a] == a)
        return a;

    return p[a] = find(p, p[a]);
}

void join(vector<int> &p, int &sets, int a, int b) {
    auto A = find(p, a);
    auto B = find(p, b);

    if (A != B) {
        --sets;
        p[A] = B;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    int sets = n;

    map<string, int> id;
    priority_queue<tuple<int, int, int>> pq;
    int cid{};

    for (int i{}; i < m; ++i) {
        string a, b;
        int cost;
        cin >> a >> b >> cost;
        if (!id.count(a))
            id[a] = cid++;
        if (!id.count(b))
            id[b] = cid++;

        pq.emplace(-cost, id[a], id[b]);
    }

    int ans{};
    while (!pq.empty() && sets > 1) {
        int cost, a, b;
        auto t = pq.top();
        pq.pop();
        tie(cost, a, b) = t;
        cost *= -1;

        auto A = find(p, a);
        auto B = find(p, b);

        if (A != B) {
            ans += cost;
            join(p, sets, A, B);
        }
    }

    cout << ans << '\n';
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
        if (tc)
            cout << '\n';
    }
}
