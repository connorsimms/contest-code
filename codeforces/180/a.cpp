#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string R;
    cin >> R;

    int l1{}, l2{}, r1{}, r2{};

    for (int i = 0; i < n; ++i) {
        if (R[i] == 'R') {
            if (r1 == 0)
                r1 = i;
            r2 = i;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (R[i] == 'L') {
            if (l2 == 0)
                l2 = i;
            l1 = i;
        }
    }

    if (r1 && l1) {
        cout << r1 + 1 << ' ' << r2 + 1;
    } else if (r1) {
        cout << r1 + 1 << ' ' << r2 + 2;
    } else {
        cout << l2 + 1 << ' ' << l1;
    }
    cout << '\n';
}
