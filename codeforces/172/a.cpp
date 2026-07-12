#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.front() >= 'a' && s.front() <= 'z')
        s.front() += 'A' - 'a';
    cout << s << '\n';
}
