#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(5), b(5);
    for (int i = 0; i < 5; ++i) {
        a[i] += n / 5;
        b[i] += m / 5;
    }
    for (int i = 1; i <= n % 5; ++i)
        ++a[i];
    for (int i = 1; i <= m % 5; ++i)
        ++b[i];

    long long ans{};

    for (int i{}; i < 5; ++i) {
        ans += a[i] * b[(5 - i) % 5];
    }
    cout << ans << '\n';
}
