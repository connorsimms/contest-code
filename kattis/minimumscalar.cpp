#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int n; cin >> n;
        vector<long long> v1(n), v2(n);

        for (int i = 0 ; i < n; ++i)
        {
            cin >> v1[i];
        }

        for (int i = 0 ; i < n; ++i)
        {
            cin >> v2[i];
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end(), greater<int>());

        cout << "Case #" << t << ": ";

        long long sp = 0;

        for (int i = 0; i < n; ++i)
        {
            sp += v1[i] * v2[i];
        }

        cout << sp << '\n';
    }
}
