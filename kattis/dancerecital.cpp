#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> routines(n);

    for (int i = 0 ; i < n; ++i) 
    { 
        string str; cin >> str;

        int mask = 0;

        for (auto x : str)
        {
            int bit = x - 'A';

            mask |= (1 << bit);
        }

        routines[i] = mask;
    }

    sort(routines.begin(), routines.end());

    int ans = 1'000'000;

    do
    {
        int changes = 0;
        for (int i = 0 ; i < n - 1; ++i)
        {
            changes += __builtin_popcount(routines[i] & routines[i + 1]);

            if (changes > ans) break;
        }
        ans = min(changes, ans);
    } while (next_permutation(routines.begin(), routines.end()));

    cout << ans << '\n';
}
