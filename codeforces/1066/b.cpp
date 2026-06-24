#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <class T> using v = vector<T>;
template <class T, class U> void chmax(T &l, const U &r) { l = l < r ? r : l; }
template <class T, class U> void chmin(T &l, const U &r) { l = l > r ? r : l; }

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;

    int num4 = 0, num8 = 0;

    for (auto c : s)
        if (c == '4')
            ++num4;
        else
            ++num8;

    if (max(abs(y), abs(x)) > num4 + num8) {
        cout << "NO\n";
        return;
    }

    if (abs(x) + abs(y) <= num4 + 2 * num8)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
