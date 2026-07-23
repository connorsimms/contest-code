#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, x, y;
    cin >> a >> x >> y;

    if (y % a == 0) {
        cout << "-1\n";
        return 0;
    }

    if (y < a) {
        if (-a < 2 * x && 2 * x < a)
            cout << "1\n";
        else
            cout << "-1\n";
        return 0;
    }

    y -= a;

    int h = y / a;

    if (h & 1) {
        if (-a < x && x < 0) {
            cout << h / 2 * 3 + 3;
        } else if (0 < x && x < a) {
            cout << h / 2 * 3 + 4;
        } else {
            cout << -1;
        }
    } else {
        if (-a < 2 * x && 2 * x < a) {
            cout << h / 2 * 3 + 2;
        } else {
            cout << -1;
        }
    }
    cout << '\n';
}
