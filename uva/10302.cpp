#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
    vector<ull> a(50001);
    a[1] = 1;
    for (ull i{2}; i <= 50000; ++i) {
        a[i] = a[i - 1] + i * i * i;
    }

    int n;
    while (cin >> n) {
        cout << a[n] << '\n';
    }
}
