#include <bits/stdc++.h>
using namespace std;

constexpr string x("tcodi");
constexpr array<char, 5> y = {4, 6, 8, 12, 20};

consteval array<int, 26> gen() {
    array<int, 26> z{};
    for (int i = 0; i < 5; ++i) {
        z[x[i] - 'a'] = y[i];
    }
    return z;
}

constexpr array<int, 26> s = gen();

int main() {
    int n;
    cin >> n;
    int ans{};
    for (int i = 0; i < n; ++i) {
        string p;
        cin >> p;
        ans += s[p[0] - 'A'];
    }
    cout << ans << '\n';
}
