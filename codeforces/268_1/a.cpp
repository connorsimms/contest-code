#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> v(n + 1);

    int p;
    cin >> p;
    for (int i = 0; i < p; ++i) {
        int l;
        cin >> l;
        v[l] = true;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l;
        cin >> l;
        v[l] = true;
    }

    bool ans = true;
    for (int i = 1; i <= n; ++i)
        if (!v[i]) ans = false;

    cout << (ans ? "I become the guy.\n" : "Oh, my keyboard!\n");
}
