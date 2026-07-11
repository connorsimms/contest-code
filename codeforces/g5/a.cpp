#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int odd{};
    for (int i{}; i < n; ++i) {
        cin >> a[i];
        if (a[i] & 1)
            ++odd;
    }

    int cnt{};
    for (auto c : a) {
        if (c & 1) {
            if (cnt < odd / 2) {
                cout << c / 2 - (c < 0);
                ++cnt;
            } else {
                cout << c / 2 + (c > 0);
            }
            cout << '\n';
        } else {
            cout << c / 2 << '\n';
        }
    }
}
