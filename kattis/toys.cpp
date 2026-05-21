#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, k; cin >> t >> k;

    int ans = 0;
    for (int i = 1 ; i <= t; ++i)
    {
        ans += k;
        ans %= i;
    }

    cout << ans << '\n';
}
