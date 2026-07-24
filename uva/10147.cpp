#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &p, int a) {
    if (p[a] == a)
        return a;

    return p[a] = find(p, p[a]);
}

void join(vector<int> &p, int &num, int a, int b) {

    auto A = find(p, a);
    auto B = find(p, b);

    if (A != B) {
        p[A] = B;
        --num;
    }
}

void solve() {
    int N;
    cin >> N;

    vector<pair<int, int>> cit(N + 1);
    vector<int> p(N + 1);
    int num = N;

    iota(p.begin(), p.end(), 0);

    for (int i{1}; i <= N; ++i)
        cin >> cit[i].first >> cit[i].second;

    int M;
    cin >> M;
    for (int i{}; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        join(p, num, a, b);
    }

    using item = tuple<int, int, int>;
    priority_queue<item, vector<item>, greater<item>> pq;

    for (int i{1}; i <= N; ++i) {
        for (int j{i + 1}; j <= N; ++j) {
            auto I = find(p, i);
            auto J = find(p, j);
            if (I != J) {
                int xi, yi, xj, yj;
                tie(xi, yi) = cit[i];
                tie(xj, yj) = cit[j];
                auto d = (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj);
                pq.emplace(d, i, j);
            }
        }
    }

    bool any = false;
    while (num != 1 && !pq.empty()) {
        int d, i, j;
        tie(d, i, j) = pq.top();
        auto I = find(p, i);
        auto J = find(p, j);
        if (I != J) {
            cout << i << ' ' << j << '\n';
            any = true;
            join(p, num, I, J);
        }
        pq.pop();
    }

    if (!any)
        cout << "No new highways need\n";
}

int main() {
    string del = "";
    int TC;
    cin >> TC;
    while (TC--) {
        cout << del;
        solve();
        del = "\n";
    }
}
