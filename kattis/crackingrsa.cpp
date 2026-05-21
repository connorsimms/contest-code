#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<bool> isPrime(1001, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < isPrime.size(); ++i)
    {
        if (!isPrime[i]) continue;

        for (int j = 2 * i; j < isPrime.size(); j += i)
        {
            isPrime[j] = false;
        }
    }

    int T; cin >> T;
    while (T--)
    {
        int n, e; cin >> n >> e;

        bool found = false;

        for (int i = 2 ; i < 1001 && !found; ++i)
        {
            if (!isPrime[i]) continue;

            if (n % i != 0) continue;

            if (!isPrime[n / i]) continue;

            int p = i;
            int q = n / i;

            int euler = (p - 1) * (q - 1);

            for (long long d = 2; d < euler && !found; ++d)
            {
                if ((d * e) % euler == 1)
                {
                    cout << d << '\n';
                    found = true;
                }
            }
        }
    }
}
