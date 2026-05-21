#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    vector<int> s(n);

    for (int i = 0 ; i < n; ++i) cin >> s[i];

    sort(s.begin(), s.end());

    long long = 0;

    for (int i = 0 ; i < m; ++i)
    {
        int q; cin >> q;

        ans += (*lower_bound(s.begin(), s.end(), q) - q);
    }

    cout << ans << '\n';
}
