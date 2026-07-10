#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long n;
    cin >> n;
    if (n & 1) {
        cout << '-' << n / 2 + 1;
    } else {
        cout << n / 2;
    }
    cout << '\n';
}
