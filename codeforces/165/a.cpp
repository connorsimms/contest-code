#include <bits/stdc++.h>
using namespace std;

int main() {
    // (n - 2) * 180 / n
    // n = 3 -> 60
    // n = 4 -> 90
    // n = 5 -> 108

    vector<bool> poss(180);

    for (int i = 3; i < 1000; ++i) {
        auto tot = (i - 2) * 180;

        if (tot % i == 0) {
            poss[tot / i] = true;
            cerr << tot / i << " possible\n";
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cout << (poss[a] ? "YES\n" : "NO\n");
    }
}
