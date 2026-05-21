#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> f(7, 0);
    vector<int> v(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        ++f[v[i]];
    }

    int best = -1;
    int winner = -1;

    for (int i = 0 ; i < n; ++i)
    {
        if (f[v[i]] == 1 && v[i] > best)
        {
            best = v[i]; 
            winner = i + 1;
        }
    }

    if (winner != -1)
        cout << winner << '\n';
    else
         cout << "none\n";
}
