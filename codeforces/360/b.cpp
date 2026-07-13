#include <bits/stdc++.h>
using namespace std;

int main() {
    // 11, 22, 33, 44, 55, 66, 77, 88, 99,
    //
    // 1001, 1111, 1221, 1331, 1441, 1551, 1661, 1771, 1881, 1991
    // 2002, ...
    // ...
    // 9009

    string s;
    cin >> s;
    cout << s;
    reverse(s.begin(), s.end());
    cout << s << '\n';
}
