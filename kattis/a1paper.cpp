#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    vector<long long> a(n + 1);

    for (size_t i = 2 ; i <= n; ++i)
    {
        cin >> a[i];
    }

    vector<long double> len(n + 1);

    for (size_t i = 0 ; i <= n; ++i)
    {
        len[i] = pow(2.0, 0.25 - i / 2.0);
    }

    if (a[2] >= 2)
    {
        cout << fixed << setprecision(8) << len[2] << '\n';
        return 0;
    }
    
    long long need = 2 - a[2];
    int smallest = -1;

    for (int i = 3; i <= n && need > 0; ++i)
    {
        need *= 2;

        auto used = min(need, a[i]);

        need -= used;

        if (need == 0)
        {
            a[i] = used;
        }

        smallest = i;
    }
    
    if (need > 0) 
    {
        cout << "impossible\n";
        return 0;
    }

    long double tape = 0.0;

    for (int i = smallest ; i > 0; --i)
    {
        long long conn = a[i] / 2;

        tape += (len[i] * conn);

        a[i - 1] += conn;
    }

    cout << fixed << setprecision(8) << tape << '\n';
}
