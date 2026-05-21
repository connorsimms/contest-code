#include <bits/stdc++.h>
using namespace std;

int main()
{
    string m; cin >> m; int n; cin >> n;

    unordered_map<char, long long> f, tf;

    for (int i = 0; i < m.size(); )
    {
        char a = m[i++];

        long long count = 0;
        while (i < m.size() && m[i] >= '0' && m[i] <= '9')
        {
            count *= 10;
            count += (m[i] - '0');
            ++i;
        }

        if (count == 0) count = 1;

        f[a] += count * n;
    }

    string t; cin >> t;

    long long ans = numeric_limits<long long>::max();

    for (int i = 0; i < t.size(); )
    {
        char a = t[i++];

        long long count = 0;
        while (i < t.size() && t[i] >= '0' && t[i] <= '9')
        {
            count *= 10;
            count += (t[i] - '0');
            ++i;
        }

        if (count == 0) count = 1;

        tf[a] += count;
    }

    for (auto [x, y]: tf)
    {
        ans = min(ans, f[x] / y);
    }

    cout << ans << '\n';
}
