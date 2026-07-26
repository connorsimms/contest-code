#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> t;
    for (int i{}; i < n; ++i) {
        int id, m;
        cin >> id >> m;
        t.emplace_back(-m, i, id);
    }
    sort(t.begin(), t.end());
    for (auto x : t) {
        int m, i, id;
        tie(m, i, id) = x;
        cout << id << ' ' << -m << '\n';
    }
}
