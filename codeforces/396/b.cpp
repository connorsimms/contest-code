#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i{}; i < n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    bool poss = false;
    for (int i{}; i < n - 2 && !poss; ++i) {
        if (v[i] + v[i + 1] > v[i + 2])
            poss = true;
    }

    cout << (poss ? "YES\n" : "NO\n");
}
