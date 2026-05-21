#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;

    vector<long long> v(N + 1); 

    for (int i = 0 ; i < Q; ++i)
    {
        char op; cin >> op;

        if (op == '+')
        {
            int idx, x; cin >> idx >> x;

            if (idx == 0) 
            {
                v[idx] += x;
                continue;
            }

            for (; idx < v.size(); idx += (idx & -idx))
            {
                v[idx] += x;
            }
        }
        else
        {
            int a; cin >> a;

            if (a == 0)
            {
                cout << 0 << '\n';
                continue;
            }

            --a;

            long long sum = 0;
            for (; a; a -= (a & -a))
            {
                sum += v[a];
            }

            sum += v[0];

            cout << sum << '\n';
        }
    }
}
