#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
constexpr ull MOD = 2e9 + 11;

vector<ull> ans(101, 1);

int main() {
    ans[1] = ans[2] = 1;
    for (ull i{2}; i <= 100; ++i) {
        for (int j{}; j < i - 2; ++j) {
            ans[i] *= i;
            ans[i] %= MOD;
        }
    }

    int TC;
    cin >> TC;
    for (int c{1}; c <= TC; ++c) {
        int n;
        cin >> n;
        cout << "Case #" << c << ": " << ans[n] << '\n';
    }
}
