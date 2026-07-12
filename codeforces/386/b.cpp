#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    deque<char> d;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        auto x = (n & 1) ? i : i + 1;
        if (x & 1) {
            d.push_front(s[i]);
        } else {
            d.push_back(s[i]);
        }
    }

    for (auto c : d)
        cout << c;
    cout << '\n';
}
