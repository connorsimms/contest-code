#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int m;
    cin >> m;

    vector<int> f(s.size());

    for (int i{}; i < m; ++i) {
        int a;
        cin >> a;
        ++f[a];
    }

    vector<int> pf(f);
    for (int i{1}; i < s.size(); ++i) {
        pf[i] += pf[i - 1];
    }

    string first{}, second{};

    for (int i{}; i < s.size() / 2; ++i) {
        int idx = i + 1;

        if (pf[idx] & 1) {
            first.push_back(s[s.size() - i - 1]);
            second.push_back(s[i]);
        } else {
            first.push_back(s[i]);
            second.push_back(s[s.size() - i - 1]);
        }
    }

    if (s.size() % 2) {
        int mid = s.size() / 2;
        first.push_back(s[mid]);
    }

    reverse(begin(second), end(second));
    cout << first << second << '\n';
}
