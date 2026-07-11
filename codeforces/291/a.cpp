#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0 && s[i] == '9') {
            cout << s[i];
            continue;
        }

        if (s[i] >= '5')
            cout << int('9' - s[i]);
        else
            cout << s[i];
    }
    cout << '\n';
}
