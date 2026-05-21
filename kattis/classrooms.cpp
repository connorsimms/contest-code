#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;

    vector<pair<int,int>> e;

    for (int i = 0; i < n; ++i)
    {
        int s, f; cin >> s >> f;
        e.emplace_back(s, f);
    }

    sort(e.begin(), e.end(), [](auto& e1, auto& e2) { 
        auto& [s1, f1] = e1;
        auto& [s2, f2] = e2;

        if (f1 == f2) return s1 < s2;
        return f1 < f2;
    });

    int ans = 0;

    vector<int> ends(k);

    for (auto& [s, f] : e)
    {
        if (ends.empty())
        {
            ends.push_back(f);
            ++ans;
        }
        else
        {
            auto it = lower_bound(ends.begin(), ends.end(), s);

            if (it == ends.begin()) 
            {
                if (ends.size() < k)
                {
                    ends.insert(lower_bound(ends.begin(), ends.end(), f), f);

                    ++ans;
                }
                continue;
            }

            --it;
            ends.erase(it);

            ends.insert(lower_bound(ends.begin(), ends.end(), f), f);
            ++ans;
        }
    }

    cout << ans << '\n';
}
