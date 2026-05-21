#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> w(n);

    for (int i = 0 ; i < n; ++i)
    {
        cin >> w[i];
    }

    long long sum = 0;
    for (int i = n - 2 ; i >= 0; --i)
    {
        if (w[i] >= w[i + 1])
        {
            if (w[i] == 0 || w[i + 1] == 0)
            {
                cout << 1 << '\n';
                return 0;
            }

            sum += w[i] - w[i + 1] + 1;

            w[i] = w[i + 1] - 1;
        }
    }

    cout << sum << '\n';
}
