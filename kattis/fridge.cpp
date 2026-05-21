#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;

    array<int, 10> a{};

    int best = 0;
    int len = 1001;

    for (auto x: s)
    {
        ++a[(x - '0')];
    }

    for (int i = 0; i <= 9; ++i)
    {
        if (a[i] < len)
        {
            len = a[i];
            best = i;
        }
    }

    if (best == 0)
    {
        cout << 1;
        --a[1];
    }

    for (int i = 0; i <= 9; ++i)
    {
        if (a[i] < len)
        {
            len = a[i];
            best = i;
        }
    }

    string ans(len + 1, '0' + best);

    cout << ans << '\n';
}
