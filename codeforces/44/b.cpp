#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, int>> w(3);

    for (int i = 0; i < 3; ++i) {
        w[i].second = i;

        string s;
        cin >> s;

        auto c1 = s[0] - 'A';
        auto c2 = s[2] - 'A';

        if (s[1] == '<') {
            ++w[c2].first;
        } else {
            ++w[c1].first;
        }
    }

    sort(w.begin(), w.end());

    if (w[0].first == w[1].first) {
        cout << "Impossible\n";
    } else {
        for (auto [v, i] : w) {
            cout << char('A' + i);
        }
        cout << '\n';
    }
}
