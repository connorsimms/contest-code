#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int x, y;
        cin >> x >> y;

        if (x < y || (x + y) % 2 != 0 || (x - y) % 2 != 0) {
            cout << "impossible\n";
            continue;
        }

        cout << (x + y) / 2 << ' ' << (x - y) / 2 << '\n';
    }
}
