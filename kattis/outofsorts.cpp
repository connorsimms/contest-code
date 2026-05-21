#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, a, c, x0; cin >> n >> m >> a >> c >> x0;

    c %= m;

    vector<long long> v(n);

    v[0] = ((((x0 % m) * a) % m) + c) % m;

    for (int i = 1; i < n; ++i)
    {
        v[i] = ((((v[i - 1] % m) * a) % m) + c) % m;
    }

    int ans = 0;
    for (auto x: v)
    {
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (v[mid] == x)
            {
                ++ans;
                break;
            }

            if (v[mid] < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    cout << ans << '\n';
}
