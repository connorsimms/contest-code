#include <bits/stdc++.h>
using namespace std;

int main() {
    double d, h, v, e;
    cin >> d >> h >> v >> e;

    double hps = v / ((d / 2) * (d / 2) * numbers::pi);

    cerr << hps << ' ' << e << '\n';

    if (hps > e) {
        cout << "YES\n";
        cout << fixed << setprecision(6) << h / (hps - e) << '\n';
    } else {
        cout << "NO\n";
    }
}
