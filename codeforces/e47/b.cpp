#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string x;

    int ones{};
    for (auto c : s) {
        if (c == '1') {
            ++ones;
        } else {
            x.push_back(c);
        }
    }

    bool printed = false;
    for (auto c : x) {
        if (c == '2' && !printed) {
            cout << string(ones, '1');
            printed = true;
        }

        cout << c;
    }
    if (!printed) {
        cout << string(ones, '1');
    }
    cout << '\n';
}
