#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        vector<char> res(32, '?');

        for (int c = 0 ; c < n ; ++c)
        {
            string cmd; int i, j;

            cin >> cmd;
            
            if (cmd == "CLEAR") { cin >> i; res[i] = '0'; }
            if (cmd == "SET")   { cin >> i; res[i] = '1'; }
            if (cmd == "OR")    
            {
                cin >> i >> j;
                if (res[i] == '1' || res[j] == '1') res[i] = '1';
                if (res[i] == '0' && res[j] == '0') res[i] = '0';
                if (res[i] == '?' && res[j] == '0') res[i] = '?';
                if (res[i] == '0' && res[j] == '?') res[i] = '?';
                if (res[i] == '?' && res[j] == '?') res[i] = '?';
            }
            if (cmd == "AND")    
            {
                cin >> i >> j;
                if (res[i] == '0' || res[j] == '0') res[i] = '0';
                if (res[i] == '1' && res[j] == '1') res[i] = '1';
                if (res[i] == '?' && res[j] == '1') res[i] = '?';
                if (res[i] == '1' && res[j] == '?') res[i] = '?';
                if (res[i] == '?' && res[j] == '?') res[i] = '?';
            }
        }

        for (int i = 31; i >= 0; --i)
        {
            cout << res[i];
        }
        cout << '\n';
    }
    
}
