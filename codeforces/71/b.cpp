#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, m, k, t;
    cin >> n >> m >> k >> t;

    vector<ll> waste(k);

    for (int i{}; i < k; ++i) {
        ll a, b;
        cin >> a >> b;
        --a, --b;
        waste[i] = a * m + b;
    }

    sort(waste.begin(), waste.end());

    for (int z{}; z < t; ++z) {
        ll i, j;
        cin >> i >> j;
        --i, --j;
        auto idx = i * m + j;

        auto it = lower_bound(waste.begin(), waste.end(), idx);

        if (it != waste.end() && *it == idx) {
            cout << "Waste\n";
            continue;
        }

        auto off = it - waste.begin();

        // cerr << off << endl;

        auto id = idx + (3 - off);

        switch (id % 3) {
        case 0: cout << "Carrots\n"; break;
        case 1: cout << "Kiwis\n"; break;
        case 2: cout << "Grapes\n"; break;
        }
    }
}
