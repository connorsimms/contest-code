#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    unordered_set<int> r;

    for (int i = 0 ; i < m; ++i)
    {
        int a, b; cin >> a >> b;

        --a; --b;

        int m = (1 << a) | (1 << b);
        r.insert(m);
    }

    int ans = 0;
    for (int i = 0 ; i < (1 << n); ++i)
    {
        bool valid = true;
        for (auto p : r)
        {
            if (__builtin_popcount(i & p) == 2)
            {
                valid = false;
                break;
            }
        }
        if (valid) ++ans;
    }

    cout << ans << '\n';
}
