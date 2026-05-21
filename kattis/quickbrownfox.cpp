#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n; cin >> n; string junk; getline(cin, junk);
    for (int i = 0 ; i < n; ++i)
    {
        string line; getline(cin, line);

        vector<bool> has(26);

        for (auto x: line)
        {
            if (x >= 'A' && x <= 'Z') has[x - 'A'] = true;
            if (x >= 'a' && x <= 'z') has[x - 'a'] = true;
        }

        string missing = "";

        for (int i = 0 ; i < 26; ++i)
        {
            if (!has[i]) missing += ('a' + i);
        }

        if (missing.empty())
        {
            cout << "pangram\n";
        }
        else
        {
            cout << "missing " << missing << '\n';
        }
    }
}
