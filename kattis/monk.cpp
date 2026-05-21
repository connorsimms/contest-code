#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b; cin >> a >> b;

    vector<pair<int, int>> asc, dsc;

    int asc_time = 0;
    int total = 0;
    for (int i = 0 ; i < a; ++i)
    {
        int h, t; cin >> h >> t; asc.emplace_back(h, t);
        asc_time += t;
        total += h;
    }

    int dsc_time = 0;
    for (int i = 0 ; i < b; ++i)
    {
        int h, t; cin >> h >> t; dsc.emplace_back(h, t);
        dsc_time += t;
    }

    double lo = 0.0, hi = min(asc_time, dsc_time) + 0.001;
    double mid = (lo + hi) / 2;

    while (hi - lo > 0.00000001)
    {
        mid = (lo + hi) / 2;

        int asc_time = 0;
        double asc_dist = 0.0; 
        
        for (int i = 0; i < a; ++i)
        {
            const auto& [h, t] = asc[i];

            if (asc_time + t < mid)
            {
                asc_time += t;
                asc_dist += h;
            }
            else 
            { 
                asc_dist += (mid - asc_time) / t * h;
                asc_time += (mid - asc_time);
                break; 
            }
        }

        int dsc_time = 0;
        double dsc_dist = 0.0;

        for (int i = 0; i < b; ++i)
        {
            const auto& [h, t] = dsc[i];

            if (dsc_time + t < mid)
            {
                dsc_time += t;
                dsc_dist += h;
            }
            else 
            { 
                dsc_dist += (mid - dsc_time) / t * h;
                dsc_time += (mid - dsc_time);
                break; 
            }
        }

        if (asc_dist + dsc_dist >= total)
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }

    cout << fixed << setprecision(6) << mid << '\n';
}
