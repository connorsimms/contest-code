#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;

        int bestG = -1;
        double bestT = -1.0;

        for (int i = 0 ; i < n; ++i)
        {
            int a, b, c; cin >> a >> b >> c;

            double val = 1.0 * b * b / 4 / a + c;

            if (val > bestT)
            {
                bestT = val;
                bestG = i;
            }
        }

        cout << bestG + 1 << '\n';
    }
}
