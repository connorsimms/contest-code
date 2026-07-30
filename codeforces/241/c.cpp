#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> ppl;
    for (int i{}; i < n; ++i) {
        int c, p;
        cin >> c >> p;
        ppl.emplace_back(p, c, i + 1);
    }

    int k;
    cin >> k;
    deque<pair<int, int>> r;
    for (int i{}; i < k; ++i) {
        int sz;
        cin >> sz;
        r.emplace_back(sz, i + 1);
    }

    sort(rbegin(ppl), rend(ppl));
    sort(begin(r), end(r));

    int money{};
    vector<pair<int, int>> ans{};

    for (auto [p, c, pid] : ppl) {
        auto it = lower_bound(begin(r), end(r), make_pair(c, 0));

        if (it == end(r))
            continue;

        auto [sz, id] = *it;

        r.erase(it);

        money += p;
        ans.emplace_back(pid, id);
    }

    cout << ans.size() << ' ' << money << '\n';
    for (auto [pid, id] : ans) {
        cout << pid << ' ' << id << '\n';
    }
}
