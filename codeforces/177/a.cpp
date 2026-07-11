#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int val{};
    for (int i{}; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        val += (r - l + 1);
    }

    if (val % k == 0)
        cout << 0 << '\n';
    else
        cout << k - val % k << '\n';
}
