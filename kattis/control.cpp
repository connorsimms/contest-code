#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;

    unordered_map<int, int> p, s; 

    int ans = 0;

    auto find_set = [&](int a, auto&& self) {
        if (a == p[a]) return a;
        else return p[a] = self(p[a], self);
    };

    auto join_set = [&](int a, int b) {
        int A = find_set(a, find_set); 
        int B = find_set(b, find_set); 

        if (A == B) return;

        s[A] += s[B];
        p[B] = A;
        s[B] = s[A];
    };

    for (int i = 0; i < n; ++i)
    {
        int m; cin >> m;

        vector<int> ings(m);
        unordered_map<int, int> freq;

        for (int j = 0 ; j < m; ++j)
        {
            cin >> ings[j];

            if (!p.count(ings[j]))
            {
                p[ings[j]] = ings[j];
                s[ings[j]] = 1;
            }

            int ing = ings[j];

            freq[find_set(ing, find_set)]++;
        }

        bool valid = true;
        for (auto& [se, f]: freq)
        {
            if (f != s[se]) valid = false;
        }

        if (valid)
        {
            for (int j = 0 ; j < m - 1; ++j)
            {
                join_set(ings[j], ings[j + 1]);
            }
            ++ans;
        }
    }
    cout << ans << '\n';
}

