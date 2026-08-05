#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using ulll = __int128_t;
ull MOD = 1e9 + 7;

ull modmult(ull a, ull b, ull mod) {
    ulll A = a, B = b;
    ulll prod = A * B;
    prod %= mod;
    return ull(prod);
}

ull modexp(ull a, ull e, ull mod) {
    ull res{
        1};
    ull cur{
        a};
    cur %= mod;
    while (e) {
        if (e & 1) {
            res = modmult(res, cur, mod);
        }
        cur = modmult(cur, cur, mod);
        e >>= 1;
    }

    return res % mod;
}

ull gcd(ull a, ull b) {
    if (a < b) swap(a, b);
    while (b) {
        ull tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        ull A, B, N;
        cin >> A >> B >> N;
        auto diff = max(A, B) - min(A, B);
        if (diff) {
            auto a = modexp(A, N, diff);
            auto b = modexp(B, N, diff);
            auto x = (a + b) % diff;
            cout << (gcd(x, diff) % MOD) << '\n';
        } else {
            auto a = modexp(A, N, MOD);
            auto b = modexp(B, N, MOD);
            cout << (a + b) % MOD << '\n';
        }
    }
}
