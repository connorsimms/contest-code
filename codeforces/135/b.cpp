#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull bpow(ull b, ull e) {
    ull res{1}, pow{b};
    while (e) {
        if (e & 1)
            res *= pow;
        pow *= pow;
        e >>= 1;
    }
    return res;
}

int main() {
    ull p, d;
    cin >> p >> d;

    ull nlo{}, nhi{18};
    ull ans{};

    while (nlo <= nhi) {
        auto nm = (nlo + nhi) / 2;

        if (p < bpow(10, nm) - 1) {
            nhi = nm - 1;
            continue;
        }

        ull lo{}, hi = (p - bpow(10, nm) + 1) / bpow(10, nm);

        bool valid = false;
        while (lo <= hi) {
            auto m = (lo + hi) / 2;

            ull amt = m * bpow(10ULL, nm) + bpow(10ULL, nm) - 1;

            if (amt <= p && p - amt <= d) {
                ans = amt;
                valid = true;
                lo = m + 1;
            } else if (amt > p) {
                hi = m - 1;
            } else {
                lo = m + 1;
            }
        }

        if (valid) {
            nlo = nm + 1;
        } else {
            nhi = nm - 1;
        }
    }

    cout << ans << '\n';
}
