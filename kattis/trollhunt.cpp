#include <bits/stdc++.h>
using namespace std;

int main()
{
    int b, k, g; cin >> b >> k >> g;

    int d = 0;
    while (b > 1)
    {
        b -= (k / g);

        ++d;
    }

    cout << d << '\n';
}
