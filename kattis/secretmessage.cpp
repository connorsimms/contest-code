#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string inp; cin >> inp;
        int len = (int)inp.size();
        auto r = sqrt(len);
        if ((int)r * (int)r == len)
        {
            
        }
        else
        {
            r = (int)ceil(r);
        }

        string suff((int)(r*r - inp.size()), '*');
        inp += suff;

        for (int i = 0; i < r; ++i)
        {
            for (int j = r - 1; j >= 0; --j)
            {
                if (inp[j * r + i] != '*')
                    cout << inp[j * r + i];    
            }
        }
        cout << '\n';
    }
}
