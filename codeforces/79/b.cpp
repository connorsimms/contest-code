#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    string s;
    cin >> s;

    int ans{};

    while (s.size() > 1) {
        ++ans;

        ll sum{};
        for (auto c : s) {
            sum += c - '0';
        }

        s = to_string(sum);
    }

    cout << ans << '\n';
}
