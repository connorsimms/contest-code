#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s1(n), s2(n), g;
    for (int i{}; i < n; ++i) {
        cin >> s1[i] >> s2[i];
        g.push_back(s1[i]);
        g.push_back(s2[i]);
    }

    sort(begin(g), end(g));

    for (const auto &v : {s1, s2}) {
        for (int i{}; i < n; ++i) {
            if (2 * (i + 1) <= n) {
                cout << 1;
                continue;
            }

            auto it = lower_bound(g.begin(), g.end(), v[i]);
            auto pos = it - g.begin();

            if (pos < n)
                cout << 1;
            else
                cout << 0;
        }
        cout << '\n';
    }
}
