#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;

int main() {
    ui sum, limit;
    cin >> sum >> limit;

    vector<pair<ui, ui>> v;

    for (ui i{1}; i <= limit; ++i) {
        v.emplace_back(i & (-i), i);
    }

    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    });

    vector<ui> ans;
    for (int i{}; sum != 0 && i < v.size(); ++i) {
        auto [lb, x] = v[i];

        if (lb <= sum) {
            ans.push_back(x);
            sum -= lb;
        }
    }

    if (sum) {
        cout << -1 << '\n';
    } else {
        cout << ans.size() << '\n';
        for (auto x : ans)
            cout << x << ' ';
        cout << '\n';
    }
}
