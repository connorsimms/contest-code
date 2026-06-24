#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1;

    for (auto c : s) {
        if (c == 'R')
            ++ans;
        else
            break;
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
