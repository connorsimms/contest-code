#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;

        vector<string> col(n);
        unordered_map<string, int> id;

        for (int i = 0; i < n; ++i)
        {
            cin >> col[i];
            id[col[i]] = i;
        }

        int m; cin >> m;

        vector<int> h(n);

        for (int i = 0; i < m; ++i)
        { 
            string a, b; cin >> a >> b;

            int x = id[a]; int y = id[b];

            h[x] |= (1 << y);
            h[y] |= (1 << x);
        }

        int ans = 0;
        vector<int> fav;

        bool found = false;

        auto gen = [&](int id, int p, auto&& self) -> void
        {
            if (__builtin_popcount(p) == n)
            {
                ++ans;

                found = true;

                return;
            }
            
            for (int i = 0 ; i < n; ++i)
            {
                // already used
                if (p & (1 << i)) continue;

                if (id == -1 || ((h[id] & (1 << i)) == 0))
                {
                    if (!found) fav.push_back(i);

                    self(i, (p | (1 << i)), self);

                    if (!found) fav.erase(fav.begin() + fav.size() - 1);
                }
            }
        };


        gen(-1, 0, gen);

        cout << ans << '\n';
        for (auto idx: fav)
        {
            cout << col[idx] << ' ';
        }
        cout << '\n';
    }
}
