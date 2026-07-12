#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int mx{};

    for (int i{}; i < n; ++i) {
        int x;
        cin >> x;
        mx = (mx < x ? x : mx);
    }

    cout << mx << '\n';
}
