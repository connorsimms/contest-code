#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i{1}; i <= n; ++i)
        cin >> v[i] >> v[i];

    int ans{};
    vector<int> l;

    for (int i{1}; i <= n; ++i) {
        auto it = lower_bound(l.begin(), l.end(), v[i]);

        if (it == l.end()) {
            l.push_back(v[i]);
            ++ans;
            continue;
        }

        if (*it != v[i]) {
            ++ans;
            it = l.insert(it, v[i]);
        }

        l.erase(next(it), l.end());
    }

    cout << ans << '\n';
}
