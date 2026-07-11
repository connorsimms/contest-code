#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    int ans = numeric_limits<int>::max();

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'R' && s[i + 1] == 'L') {
            auto t = (p[i + 1] - p[i]) / 2;
            ans = (ans > t ? t : ans);
        }
    }

    if (ans == numeric_limits<int>::max())
        cout << "-1\n";
    else
        cout << ans << '\n';
}
