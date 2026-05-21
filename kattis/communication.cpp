#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    for (int i = 0 ; i < n; ++i)
    {
        int x; cin >> x;

        for (int j = 0 ; j <= 255; ++j)
        {
            if (((j ^ (j << 1)) & (255)) == x)
            {
                cout << j << " ";
                break;
            }
        }
    }
}
