#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int m, r; cin >> m >> r;

        vector<int> ft(m + r + 1);
        vector<int> idx(m + 1);

        int top = m + 1;

        iota(idx.rbegin(), idx.rend(), 1);

        for (int i = 1 ; i < top; ++i)
        {
            int id = i;
            for (; id < ft.size(); id += (id & -id))
            {
                ++ft[id];
            }
        }

        for (int i = 0 ; i < r; ++i)
        {
            int x; cin >> x;

            int sum = 0;

            // query
            for (int id = idx[x] - 1; id; id -= (id & -id))
            {
                sum += ft[id];
            }

            cout << m - sum - 1 << ' ';

            // remove
            for (int id = idx[x]; id < ft.size(); id += (id & -id))
            {
                --ft[id];
            }

            // add
            for (int id = top; id < ft.size(); id += (id & -id))
            {
                ++ft[id];
            }
            
            idx[x] = top;
            ++top;
        }
         

        cout << '\n';
    }
}
