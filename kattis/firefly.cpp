#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, h; cin >> n >> h;

    vector<int> up(h + 1), down(h + 1);

    for (int i = 0 ; i < n / 2; ++i)
    {
        int d, u; cin >> d >> u;

        ++down[d]; ++up[h - u + 1];
    }

    for (int i = h - 1; i >= 0; --i)
    {
        down[i] += down[i + 1];
    }

    for (int i = 1 ; i <= h; ++i)
    {
        up[i] += up[i - 1];
    }

    int min = 200'001;
    int num = 0;
    for (int i = 1 ; i <= h; ++i)
    {
        if (down[i] + up[i] == min)
        {
            ++num;
        }

        if (down[i] + up[i] < min)
        {
            min = down[i] + up[i];
            num = 1;
        }
    }

    cout << min << " " << num << '\n';
}
