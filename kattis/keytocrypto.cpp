#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s; string w; cin >> s >> w;

    for (int i = 0 ; i < min(w.size(), s.size()); ++i)
    {
        int off = (26 + s[i] - w[i]) % 26;
        s[i] = 'A' + off;
        cout << s[i];
    }

    for (int i = w.size(); i < s.size(); ++i)
    {
        int off = (26 + s[i] - s[i - w.size()]) % 26;
        s[i] = 'A' + off;
        cout << s[i];
    }
}
