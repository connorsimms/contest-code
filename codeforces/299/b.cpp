#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    ll ans{0};

    for (auto c : s) {
        if (c == '4') {
            ans *= 2;
            ans += 1;
        } else {
            ans *= 2;
            ans += 2;
        }
    }
    cout << ans << '\n';
}
