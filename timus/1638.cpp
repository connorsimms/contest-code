#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if (a == b) {
        cout << x;
    } else if (a < b) {
        cout << (b - a) * 2 * y + (b - a - 1) * x;
    } else {
        cout << (a - b) * 2 * y + (a - b + 1) * x;
    }
    cout << '\n';
}
