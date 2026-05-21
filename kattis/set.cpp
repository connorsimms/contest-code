#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> cards(12);
    for (int i = 0 ; i < 12; ++i) { cin >> cards[i]; }

    vector<tuple<int,int,int>> ans;

    for (int mask = 0 ; mask < (1 << 12); ++mask)
    {
        if (__builtin_popcount(mask) != 3) continue;

        vector<unordered_set<char>> c(4);

        for (int i = 0 ; i < 12; ++i)
        {
            if (mask & (1 << i))
            {
                c[0].insert(cards[i][0]);
                c[1].insert(cards[i][1]);
                c[2].insert(cards[i][2]);
                c[3].insert(cards[i][3]);
            }
        }

        bool valid = true;
        for (auto& x : c)
        {
            if (x.size() != 3 && x.size() != 1)
            {
                valid = false; 
            }
        }

        if (!valid) continue;

        vector<int> x;
        for (int i = 0 ; i < 12; ++i)
        {
            if (mask & (1 << i))
            {
                x.push_back(i + 1);
            }
        }
        
        ans.emplace_back(x[0], x[1], x[2]);
    }

    sort(ans.begin(), ans.end());

    if (ans.empty()) 
    {
        cout << "no sets\n";
        return 0;
    }

    for (auto& [a, b, c] : ans)
    {
        cout << a << " " << b << " " << c << '\n';
    }
}
