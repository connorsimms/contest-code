#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.size() < 3) {
        cout << s << '\n';
        return 0;
    }

    vector<int> w(s.size(), true);
    for (int i = 0; i < s.size() - 2;) {
        if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
            w[i] = w[i + 1] = w[i + 2] = false;
            i += 3;
        } else {
            i += 1;
        }
    }

    for (int i = 0; i < s.size(); ++i) {
        if (w[i]) {
            cout << s[i];
            if ((i < s.size() - 1) && !w[i + 1])
                cout << ' ';
        }
    }
    cout << '\n';
}
