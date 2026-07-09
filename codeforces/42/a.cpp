#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> x;
    int mx{};
    string w;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (++x[s] > mx) {
            mx = x[s];
            w = s;
        }
    }

    cout << w << '\n';
}
