#include <bits/stdc++.h>
using namespace std;
int main()
{
    int D; cin >> D;

    for (int i = 1; i * i <= D; ++i)
    {
        if (D % i != 0) continue;

        // i < j
        int j = D / i;

        //cout << i << ", " << j << '\n';
        
        // i = b - a, j = b + a

        int b = (i + j) / 2;
        int a = (j - i) / 2;

        if (b * b - a * a == D)
        {
            cout << a << " " << b << '\n';
            return 0;
        }
    }

    cout << "impossible\n";
}
