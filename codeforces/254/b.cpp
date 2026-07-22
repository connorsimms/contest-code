#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n + 1);
    int numSets{n};

    auto find = [&](auto &&rec, int a) {
        if (a == p[a])
            return a;

        p[a] = rec(rec, p[a]);
        return p[a];
    };

    auto join = [&](int a, int b) {
        int x = find(find, a);
        int y = find(find, b);
        if (x != y) {
            p[x] = y;
            --numSets;
        }
    };

    iota(p.begin(), p.end(), 0);

    for (int i{}; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        join(a, b);
    }

    set<int> s;
    for (int i{1}; i <= n; ++i) {
        find(find, i);
        s.insert(p[i]);
    }

    cout << (1LL << (n - numSets)) << '\n';
}
