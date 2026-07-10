#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int ms = (1 << (k + 1)) - 1;
    int ans{};

    for (int i = 0; i < n; ++i) {
        int bs = 0;
        string s;
        cin >> s;

        for (auto c : s) {
            bs |= (1 << (c - '0'));
        }

        if ((bs & ms) == ms) {
            ++ans;
        }
    }
    cout << ans << '\n';
}
