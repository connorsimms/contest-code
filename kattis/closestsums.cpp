#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; int t = 0;
    while (cin >> n)
    {
        cout << "Case " << ++t << ":\n";

        vector<int> v(n);
        for (int i = 0 ; i < n; ++i)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        int m; cin >> m;

        for (int i = 0 ; i < m; ++i)
        {
            int q; cin >> q;

            int bestSum = v[0] + v[1];

            for (int j = 0 ; j < n; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    if (abs(v[j] + v[k] - q) < abs(bestSum - q))
                    {
                        bestSum = v[j] + v[k];
                    }
                }
            }

            cout << "Closest sum to " << q << " is " << bestSum << ".\n";
        }
    }
}
