#include <bits/stdc++.h>
using namespace std;

int main() {
    // c:d
    // a:b
    // a / c < b / d

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * d < b * c) {
        // (b * c - d * a) / b * c
        int num = b * c - d * a;
        int den = b * c;
        int div = gcd(num, den);
        num /= div;
        den /= div;
        cout << num << "/" << den << '\n';
    } else {
        // (a * d - c * b) / a * d
        int num = a * d - c * b;
        int den = a * d;
        int div = gcd(num, den);
        num /= div;
        den /= div;
        cout << num << "/" << den << '\n';
    }
}
