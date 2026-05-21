#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    unordered_map<int, int> f;

    vector<int> l;

    for (int i = 0 ; i < n ; ++i)
    {
        l.push_back(i);
        cin >> f[i];
    }

    int idx = 0;

    while (l.size() > 1)
    {
        int k = f[l[idx]];

        idx += k - 1;
        idx %= l.size();

        auto toRemove = idx;

        if (idx == l.size() - 1)
        {
            idx = 0;
        }

        l.erase(l.begin() + toRemove);
    }

    cout << l.front() + 1 << '\n';
}
