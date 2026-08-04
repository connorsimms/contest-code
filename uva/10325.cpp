#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ul = unsigned long;

ull gcd(ull a, ull b) {
    if (a < b)
        swap(a, b);

    while (b) {
        auto tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

ull lcm(ull a, ull b) {
    return a / gcd(a, b) * b;
}

int main() {
    ull N;
    ull M;
    while (cin >> N >> M) {
        set<ull> s;
        for (size_t i{}; i < M; ++i) {
            ull x;
            cin >> x;
            s.insert(x);
        }

        vector<ull> m;
        for (auto x : s) {
            bool valid = true;
            for (auto y : m) {
                if (x % y == 0)
                    valid = false;
            }
            if (valid)
                m.push_back(x);
        }
        M = m.size();

        ll ans{};
        for (ull i{}; i < (1 << M); ++i) {
            ull prod{1};

            bool valid = true;
            for (size_t j{}; valid && j < M; ++j) {
                if (i & (1 << j)) {
                    prod = lcm(prod, m[j]);
                }

                if (prod > N)
                    valid = false;
            }

            ull amt = N / prod;
            if (valid) {
                if (__builtin_popcount(i) & 1) {
                    ans -= amt;
                } else {
                    ans += amt;
                }
            }
        }

        cout << ans << '\n';
    }
}
