#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    unordered_map<char, int> finger;
    finger['c'] = 0b1111001110;
    finger['d'] = 0b0111001110;
    finger['e'] = 0b0011001110;
    finger['f'] = 0b0001001110;
    finger['g'] = 0b0000001110;
    finger['a'] = 0b0000000110;
    finger['b'] = 0b0000000010;
    finger['C'] = 0b0000000100;
    finger['D'] = 0b0111001111;
    finger['E'] = 0b0011001111;
    finger['F'] = 0b0001001111;
    finger['G'] = 0b0000001111;
    finger['A'] = 0b0000000111;
    finger['B'] = 0b0000000011;


    int T; cin >> T;
    string line;
    getline(cin, line);
    while (T--)
    {
        getline(cin, line);
        vector<int> ans(10, 0);

        int pMask = 0;
        for (auto n: line)
        {
            for (int i = 0 ; i < 10; ++i)
            {
                if ( (((1 << i) & finger[n]) != 0) && (((1 << i) & pMask) == 0))
                {
                    ans[i]++;
                }
            }
            pMask = finger[n];
        }
        for (auto x: ans)
        {
            cout << x << " ";
        }
        cout << '\n';
    }
}
