#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long w1{}, w2{};
    vector<int> m1{}, m2{};
    bool last;

    for (int i{}; i < n; ++i) {
        int x;
        cin >> x;

        if (i == n - 1)
            last = x > 0;

        if (x > 0) {
            w1 += x;
            m1.push_back(x);
        } else {
            x *= -1;
            w2 += x;
            m2.push_back(x);
        }
    }

    if (w1 != w2) {
        cout << (w1 > w2 ? "first\n" : "second\n");
        return 0;
    }

    for (int i{}; i < min(m1.size(), m2.size()); ++i) {
        if (m1[i] != m2[i]) {
            cout << (m1[i] > m2[i] ? "first\n" : "second\n");
            return 0;
        }
    }

    if (m1.size() != m2.size()) {
        cout << (m1.size() > m2.size() ? "first\n" : "second\n");
        return 0;
    }

    cout << (last ? "first\n" : "second\n");
}
