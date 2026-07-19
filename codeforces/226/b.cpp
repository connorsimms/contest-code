#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    deque<pair<int, int>> bears;

    for (int i = 0; i < int(S.size()) - 3; ++i) {
        if (S.substr(i, 4) == "bear") {
            bears.emplace_back(i, i + 3);
        }
    }

    long long ans{};
    int pos{};

    while (!bears.empty()) {
        auto [l, r] = bears.front();
        if (pos > l) {
            bears.pop_front();
            continue;
        }
        ans += S.size() - r;
        ++pos;
    }

    cout << ans << '\n';
}
