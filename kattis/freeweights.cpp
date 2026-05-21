#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    vector<long long> r1(n);
    vector<long long> r2(n);

    long long largest = 0;

    for (int i = 0 ; i < n; ++i) { cin >> r1[i]; largest = max(largest, r1[i]); }
    for (int i = 0 ; i < n; ++i) { cin >> r2[i]; largest = max(largest, r2[i]); }

    auto check = [&](long long h, auto&& self) -> bool {
        long long last = -1;
        for (int i = 0; i < n; ++i)
        {
            if (r1[i] <= h) continue;

            if (last == -1)
            {
                last = r1[i];
            }
            else
            {
                if (r1[i] != last)
                {
                    return false;
                }
                last = -1;
            }
        }

        if (last != -1) return false;

        last = -1;
        for (int i = 0; i < n; ++i)
        {
            if (r2[i] <= h) continue;

            if (last == -1)
            {
                last = r2[i];
            }
            else
            {
                if (r2[i] != last)
                {
                    return false;
                }
                last = -1;
            }
        }

        return true;
    };

    long long l = 0; long long r = largest;

    long long best = largest;

    while (l <= r)
    {
        long long mid = (l + r) / 2;

        if (check(mid, check))
        {
            best = min(best, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << best << '\n';
}
