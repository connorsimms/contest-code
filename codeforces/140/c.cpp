#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll exp(ll a, ll b, ll mod) {
    ll res{1};
    ll pow{a};
    while (b) {
        if (b & 1) {
            res *= pow;
            res %= mod;
        }
        b >>= 1;
        pow *= pow;
        pow %= mod;
    }
    return res;
}

int main() {
    ll n, m;
    cin >> n >> m;
    cout << (exp(3, n, m) + (m - 1)) % m << '\n';
}
