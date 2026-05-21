#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int l, n; cin >> l >> n;

        int fast = 0;
        int slow = 0;

        for (int i = 0; i < n; ++i)
        {
            int x; cin >> x;

            slow = max(slow, max(x, l - x));
            fast = max(fast, min(x, l - x));
        }

        cout << fast << " " << slow << '\n';
    }
}
