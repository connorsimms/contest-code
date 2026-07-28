#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
    ull l, r;
    cin >> l >> r;
    cout << "YES\n";
    for (ull i{l}; i < r; i += 2) {
        cout << i << ' ' << i + 1 << '\n';
    }
}
