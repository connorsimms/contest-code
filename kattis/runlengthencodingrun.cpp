#include <iostream>
using namespace std;

int main()
{
    char m; cin >> m; string s; cin >> s;
    if (m == 'E')
    {
        int cnt{1}; char prev = '#';
        for (int i{}; i < s.size(); ++i) 
        {
            if (s[i] == prev) { ++cnt; }
            else { 
                if (prev != '#') {cout << prev << cnt;}
                cnt = 1; 
            }
            prev = s[i];
        }
        if (cnt != 0) { cout << prev << cnt; }
    }
    else
    {
        for (int i = 0 ; i < s.size(); i += 2)
        {
            char c = s[i]; int n = s[i + 1] - '0';
            for (int j{}; j < n; ++j) { cout << c; }
        }
        cout << '\n';
    }
}
