#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string s; cin >> s; int sz = (int)s.size();
    int r = 1, c = sz;
    for (int i = (int)sqrt(sz); i >= 0; --i)
    {
        if (sz % i == 0) {
            r = i; c = sz / r;
            break;
        }
    }

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0 ; j < c; ++j)
        {
            cout << s[j * r + i];
        }
    }
    cout << '\n';
}
