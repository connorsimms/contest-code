#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string word; cin >> word;

    vector<string> out = vector(5, string(word.size() * 4 + 1, '.'));

    for (int r = 0 ; r < 5; ++r)
    {
        int mod;
        if (!(r % 2)) { mod = 4; } else { mod = 2; }
        for (int c = 0 ; c < word.size() * 4 + 1 ; ++c)
        {
            if (!((c + 6 - r) % mod)) 
            { 
                char x = '#';
                if ((c != 0 && c % 12 == 0) || (c != word.size() * 4 && c % 12 >= 8 && c % 12 <= 11)) 
                { 
                    x = '*'; 
                }
                out[r][c] = x;
            } 
        }
    }

    out[0][0] = out[4][0] = out[0][word.size() * 4] = out[4][word.size() * 4] = '.';

    for (int c = 2, j = 0; j < word.size() && c < word.size() * 4 + 1; c += 4, ++j)
    {
        out[2][c] = word[j];
    }

    for (auto r : out)
    {
        cout << r << '\n';
    }
}
