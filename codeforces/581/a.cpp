#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.size() == 1) {
        cout << 0 << '\n';
        return 0;
    }

    int cnt{};
    for (auto c : s)
        if (c == '1')
            ++cnt;

    int ans{};
    for (int i = 0; i < s.size(); i += 2) {
        if (i == s.size() - 1) {
            ans += cnt != 1;
            continue;
        }

        ++ans;
    }

    cout << ans << '\n';
}
