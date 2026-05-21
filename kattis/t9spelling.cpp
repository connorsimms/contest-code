#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<char, string> m;
    m[' '] = "0";
    for (char i = 'a'; i < 'p'; ++i)
    {
        int off = (i - 'a');
        int offMod = off % 3;
        string dig = to_string(off / 3 + 2);
        m[i] = dig;

        for (int k = 0 ; k < offMod; ++k) { m[i] += dig; }
    }
    for (char i = 't'; i < 'w'; ++i)
    {
        int off = (i - 't');
        int offMod = off % 3;
        string dig = to_string(off / 3 + 8);
        m[i] = dig;

        for (int k = 0 ; k < offMod; ++k) { m[i] += dig; }
    }
    for (char i = 'p'; i < 't'; ++i)
    {
        int off = (i - 'p');
        int offMod = off % 4;
        string dig = to_string(off / 4 + 7);
        m[i] = dig;

        for (int k = 0 ; k < offMod; ++k) { m[i] += dig; }
    }
    for (char i = 'w'; i <= 'z'; ++i)
    {
        int off = (i - 'w');
        int offMod = off % 4;
        string dig = to_string(off / 4 + 9);
        m[i] = dig;

        for (int k = 0 ; k < offMod; ++k) { m[i] += dig; }
    }

    int T; cin >> T;
    string jnk; getline(cin, jnk);
    for (int t = 1; t <= T; ++t)
    {
        cout << "Case #" << t << ": ";
        string inp; getline(cin, inp);

        string res = "";
        for (auto x: inp) { 
            if (m[x][0] == res.back()) { res += " "; }
            res += m[x]; 
        }
        cout << res << '\n';
    }
}
