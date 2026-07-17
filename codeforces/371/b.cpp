#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i{}; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }

    if (s.size() > 3) {
        cout << "NO\n";
        return 0;
    }

    if (s.size() < 3) {
        cout << "YES\n";
        return 0;
    }

    vector<int> v;
    for (auto x : s)
        v.push_back(x);

    if (v[1] - v[0] == v[2] - v[1])
        cout << "YES\n";
    else
        cout << "NO\n";
}
