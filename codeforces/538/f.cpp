#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ull MOD = 1e9 + 7;

vector<bool> isPrime(301, true);
vector<int> primes;

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (size_t i{2}; i < isPrime.size(); ++i) {
        if (!isPrime[i])
            continue;

        primes.push_back(i);

        for (size_t j{i * i}; j < isPrime.size(); j += i) {
            isPrime[j] = false;
        }
    }
}

ull exp(ull a, ull e) {
    ull x{a};
    ull res{1ULL};
    while (e) {
        if (e & 1ULL) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        e >>= 1;
    }
    return res % MOD;
}

ull euler(ull a, ull mask) {
    ull ans = a;
    for (size_t i{}; i < primes.size(); ++i) {
        if (mask & (1ULL << i)) {
            ans *= primes[i] - 1;
            ans %= MOD;
            ans *= exp(primes[i], MOD - 2);
            ans %= MOD;
        }
    }
    return ans % MOD;
}

int main() {
    sieve();

    size_t N, Q;
    cin >> N >> Q;

    size_t sz{1};
    while (sz < N)
        sz <<= 1;

    vector<int> a(sz, 1);
    for (size_t i{}; i < N; ++i)
        cin >> a[i];

    vector<pair<ull, ull>> t(4 * sz), lazy(4 * sz, make_tuple(1, 0));

    auto L = [](int v) { return (v << 1); };
    auto R = [](int v) { return (v << 1) + 1; };

    auto build = [&](auto &&rec, int v, int l, int r) -> void {
        if (l == r) {
            t[v].first = a[l];
            for (size_t i{}; i < primes.size(); ++i)
                if (a[l] % primes[i] == 0)
                    t[v].second |= (1ULL << i);
            return;
        }

        auto m = (l + r) / 2;
        rec(rec, L(v), l, m);
        rec(rec, R(v), m + 1, r);

        t[v].first = (t[L(v)].first * t[R(v)].first) % MOD;
        t[v].second = t[L(v)].second | t[R(v)].second;
    };

    auto push = [&](int v, int l, int r) {
        auto m = (l + r) / 2;

        t[L(v)].first *= exp(lazy[v].first, m - l + 1);
        t[L(v)].first %= MOD;
        t[L(v)].second |= lazy[v].second;
        lazy[L(v)].first *= lazy[v].first;
        lazy[L(v)].first %= MOD;
        lazy[L(v)].second |= lazy[v].second;

        t[R(v)].first *= exp(lazy[v].first, r - m);
        t[R(v)].first %= MOD;
        t[R(v)].second |= lazy[v].second;
        lazy[R(v)].first *= lazy[v].first;
        lazy[R(v)].first %= MOD;
        lazy[R(v)].second |= lazy[v].second;

        lazy[v].first = 1;
        lazy[v].second = 0;
    };

    auto update = [&](auto &&rec, int v, int l, int r, int i, int j, ll x) -> void {
        if (i > j)
            return;

        if (l == i && r == j) {
            t[v].first *= exp(x, j - i + 1);
            t[v].first %= MOD;
            lazy[v].first *= x;
            lazy[v].first %= MOD;
            for (size_t k{}; k < primes.size(); ++k) {
                if (x % primes[k] == 0) {
                    t[v].second |= (1ULL << k);
                    lazy[v].second |= (1ULL << k);
                }
            }
            return;
        }

        push(v, l, r);

        auto m = (l + r) / 2;
        rec(rec, L(v), l, m, i, min(j, m), x);
        rec(rec, R(v), m + 1, r, max(i, m + 1), j, x);

        t[v].first = (t[L(v)].first * t[R(v)].first) % MOD;
        t[v].second = t[L(v)].second | t[R(v)].second;
    };

    auto query = [&](auto &&rec, int v, int l, int r, int i, int j) -> pair<ull, ull> {
        if (i > j)
            return make_pair(1, 0);

        if (l == i && r == j) {
            return t[v];
        }

        push(v, l, r);

        auto m = (l + r) / 2;
        auto ql = rec(rec, L(v), l, m, i, min(j, m));
        auto qr = rec(rec, R(v), m + 1, r, max(i, m + 1), j);

        auto prod = (ql.first * qr.first) % MOD;
        auto mask = ql.second | qr.second;

        return make_pair(prod, mask);
    };

    build(build, 1, 0, sz - 1);

    for (size_t i{}; i < Q; ++i) {
        string type;
        cin >> type;

        if (type == "TOTIENT") {
            int l, r;
            cin >> l >> r;
            --l, --r;
            auto res = query(query, 1, 0, sz - 1, l, r);
            cout << euler(res.first, res.second) % MOD << '\n';
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;
            update(update, 1, 0, sz - 1, l, r, x);
        }
    }
}
