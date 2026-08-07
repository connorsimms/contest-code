#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
    ull a, b;
    cin >> a >> b;

    auto p = lcm(a, b);

    auto dasha = p / a;
    auto masha = p / b;

    if (a < b)
        ++masha;

    if (a > b)
        ++dasha;

    if (dasha == masha)
        cout << "Equal\n";
    else
        cout << (dasha > masha ? "Dasha\n" : "Masha\n");
}
