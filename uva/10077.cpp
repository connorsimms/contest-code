#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int tn, td;
    while (cin >> tn >> td && !(tn == 1 && td == 1)) {
        pair<ll, ll> lp{0, 1}, rp{1, 0}, cur{1, 1};

        while (tn * cur.second != td * cur.first) {
            if (tn * cur.second < td * cur.first) {
                cout << 'L';
                ll nn = cur.first + lp.first;
                ll nd = cur.second + lp.second;
                rp.first = cur.first;
                rp.second = cur.second;
                cur.first = nn;
                cur.second = nd;
            } else {
                cout << 'R';
                ll nn = cur.first + rp.first;
                ll nd = cur.second + rp.second;
                lp.first = cur.first;
                lp.second = cur.second;
                cur.first = nn;
                cur.second = nd;
            }
        }

        cout << '\n';
    }
}
