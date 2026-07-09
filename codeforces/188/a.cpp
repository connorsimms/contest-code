#include <iostream>

using namespace std;
using ull = unsigned long long;

int main() {
    ull n, k;
    cin >> n >> k;

    ull numOdd = (n / 2) + (n & 1); // 4 1 2 3 4 -> 2, 5 1 2 3 4 5-> 3

    // kth even
    if (k > numOdd) {
        k -= numOdd;
        cout << k * 2 << '\n';
    } else { // kth odd
        cout << k * 2 - 1 << '\n';
    }
}
