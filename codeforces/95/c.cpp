#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

// n * (n-1) * (n-2) * ... * (n-k+1) / k * (k-1) ... (1)
ull choose(ull n, ull k) {
    if (n < k)
        return 0;
    if (k == 0 || n == k)
        return 1;

    if (n - k < k)
        k = n - k;

    ull res{1};
    for (ull i{}; i < k; ++i) {
        res *= n - i;
        res /= i + 1;
    }

    return res;
}

int main() {
    int b, g, k;
    cin >> b >> g >> k;

    ull ans = choose(b + g, k);
    ans -= choose(g, k - 3) * choose(b, 3);
    ans -= choose(g, k - 2) * choose(b, 2);
    ans -= choose(g, k - 1) * choose(b, 1);
    ans -= choose(g, k);
    ans -= choose(b, k);

    cout << ans << '\n';
}
