#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if ((n & 1) == 0) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i{}, j{n - 1}; i < n && j >= 0; ++i, --j)
        cout << (n + i - j) % n << ' ';
    cout << '\n';
    for (int i{n - 1}; i >= 0; --i)
        cout << i << ' ';
    cout << '\n';
    for (int i{}; i < n; ++i)
        cout << i << ' ';
    cout << '\n';
}
