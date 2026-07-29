#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> f(26);
    for (auto c : s)
        ++f[c - 'a'];

    int numOdd{};
    for (auto x : f) {
        if (x & 1) ++numOdd;
    }

    if (numOdd <= 1) {
        cout << "First\n";
        return 0;
    }

    if (numOdd & 1) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
}

// abccdd -> 2 odd (1)
// abcdd -> 3 odd (2)
// abdd -> 2 odd (1)
//      -> 4 odd (1)
// abcddee -> 3 odd
// abcdffgg -> 4 odd
