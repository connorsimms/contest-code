#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;

        vector<int> a(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        int ans = 0, l = 0, r = 0;
        bool hasM = false;

        for (int i = 0; i < n; ++i)
        {
            // reset
            if (a[i] < m)
            {
                l = r = 0;
                hasM = false;
                continue;
            }

            // use prev sum
            if (a[i] == m && hasM)
            {
                l = r; r = 0;
                hasM = false;
            }

            if (hasM)
            {
                r += a[i];
                ans = max(ans, l + r);
            }
            else
            {
                l += a[i];

                if (a[i] == m) 
                {
                    hasM = true;
                    ans = max(ans, l + r);
                }
            }
        }

        if (hasM)
        {
            ans = max(ans, l + r);
        }

        cout << ans << '\n';
    }
}
