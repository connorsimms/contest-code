#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &p, int a) {
    if (p[a] == a)
        return a;

    return p[a] = find(p, p[a]);
}

void join(vector<int> &p, int a, int b) {
    int A = find(p, a);
    int B = find(p, b);

    if (A != B) {
        p[A] = B;
    }
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> p(N + 1);
    iota(p.begin(), p.end(), 0);
    vector<tuple<int, int, int>> con;
    using item = tuple<int, int, int>;
    priority_queue<item, vector<item>, greater<item>> pq;
    for (int i{}; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        con.emplace_back(a, b, c);
        pq.emplace(c, a, b);
    }

    int mnCost{};
    int mnDiff = 1e9 + 1;

    while (!pq.empty()) {
        int c, a, b;
        tie(c, a, b) = pq.top();
        if (a > b) swap(a, b);
        int A = find(p, a);
        int B = find(p, b);
        if (A > B) swap(A, B);

        if (A != B) {
            mnCost += c;
            for (auto e : con) {
                int x, y, C;
                tie(x, y, C) = e;
                if (x > y) swap(x, y);
                int X = find(p, x);
                int Y = find(p, y);
                if (X > Y) swap(X, Y);
                if (!(x == a && y == b) && A == X && B == Y) {
                    mnDiff = min(mnDiff, C - c);
                }
            }
            join(p, A, B);
        }

        pq.pop();
    }

    cout << mnCost << ' ' << mnCost + mnDiff << '\n';
}

int main() {
    int TC;
    cin >> TC;
    while (TC--)
        solve();
}
