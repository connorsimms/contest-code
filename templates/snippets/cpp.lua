local ls = require("luasnip")
local s = ls.snippet
local i = ls.insert_node
local fmt = require("luasnip.extras.fmt").fmt

return {
  -- Binary Exponentiation
  s("binpow", fmt([[
long long binpow(long long a, long long b) {{
    long long res = 1;
    while (b > 0) {{
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }}
    return res;
}}
{}
    ]], { i(0) })),

  -- Binary Exponentiation (Modulo)
  s("binpowmod", fmt([[
long long binpow(long long a, long long b, long long m) {{
    a %= m;
    long long res = 1;
    while (b > 0) {{
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }}
    return res;
}}
{}
    ]], { i(0) })),

  -- Modular Inverse (m is prime)
  s("modinv", fmt([[
long long modinv(long long n, long long m) {{
    return binpow(n, m - 2, m);
}}
{}
    ]], { i(0) })),

  -- Combinatorics / Factorials
  s("ncr", fmt([[
const int MAXN = {};
const int MOD = {};
long long fact[MAXN], invFact[MAXN];

void precompute() {{
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {{
        fact[i] = (fact[i - 1] * i) % MOD;
    }}
    invFact[MAXN - 1] = binpow(fact[MAXN - 1], MOD - 2, MOD);
    for (int i = MAXN - 2; i >= 1; i--) {{
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }}
}}

long long nCr(int n, int r) {{
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}}
{}
    ]], {
    i(1, "1e6 + 5"),
    i(2, "1e9 + 7"),
    i(0)
  })),
}
