#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, M; cin >> n >> M;

    vector<pair<long long,long long>> op;

    for (int i = 0 ; i < n; ++i)
    {
        long long p, c; cin >> p >> c;

        op.emplace_back(p, c);
    }
    
    sort(op.begin(), op.end(), [](auto& x, auto& y)
    {
        auto& [p1, c1] = x;
        auto& [p2, c2] = y;

        if (p1 * c2 == p2 * c1)
         {
            return p1 > p2;
         }

        return p1 * c2 > p2 * c1;  
    });

    long long ans = numeric_limits<long long>::max();
    
    long long ppd = 0, cost = 0;

    for (int i = 0 ; i < n; ++i)
    {
        auto& [p, c] = op[i];

        ppd += p;
        cost += c;

        long long dur = (cost + M) / ppd + (((cost + M) % ppd) != 0);
        ans = min(ans, dur);
    }

    cout << ans << '\n';
}
