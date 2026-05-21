#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int n; 
    while (cin >> n && n != 0)
    {
        string s; cin >> s;
        string ciph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
        unordered_map<char, char> m;
        for (int i{}; i < ciph.size(); ++i) {
            m[ciph[i]] = ciph[(i + n) % ciph.size()];
        }

        reverse(s.begin(), s.end());

        for (auto& c: s) {
            c = m[c];
        }

        cout << s << '\n';
    }
}
