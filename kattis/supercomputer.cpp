#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k; cin >> n >> k;

    vector<int> b(n + 1);
    vector<int> v(n + 1);

    for (int i = 0 ; i < k ; ++i)
    {
        char cmd; cin >> cmd;
        if (cmd == 'F')
        {
            int idx; cin >> idx;

            int op = b[idx] ? -1 : 1;
            b[idx] += op;

            for (; idx < v.size(); idx += (idx & -idx))
            {
                v[idx] += op; 
            }
        }
        else
        {
            int l, r; cin >> l >> r;

            int sum = 0;

            for (; r; r -= (r & -r))
            {
                sum += v[r]; 
            }
            l--;
            for (; l > 0; l -= (l & -l))
            {
                sum -= v[l]; 
            }

            cout << sum << '\n';
        }
    }
}
