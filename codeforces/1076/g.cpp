#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using vec = vector<T>;
template <class T, class U> void chmax(T &l, const U &r) { l = r > l ? r : l; }
template <class T, class U> void chmin(T &l, const U &r) { l = r < l ? r : l; }
template <class T> T INF() { return numeric_limits<T>::max(); }

void solve() {
    int n;
    cin >> n;
    vec<vec<int>> adj(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int response = -2;

    auto query = [&](int a, int b) {
        cout << "? " << a << ' ' << b << endl;
        cin >> response;
    };

    auto answer = [&](int a) {
        cout << "! " << a << endl;
    };

    vec<int> nodes;

    auto dfs = [&](int prev, int curr, auto &&self) -> void {
        nodes.push_back(curr);
        for (auto n : adj[curr])
            if (n != prev) self(curr, n, self);
    };

    dfs(-1, 1, dfs);

    for (int i = 0; i < nodes.size() - 1; i += 2) {
        int a = nodes[i];
        int b = nodes[i + 1];

        query(a, b);

        if (response) {
            query(a, a);
            if (response)
                answer(a);
            else
                answer(b);
            return;
        }
    }

    answer(nodes.back());

    return;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) solve();
}
