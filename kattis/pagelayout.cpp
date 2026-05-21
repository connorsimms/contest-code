#include <bits/stdc++.h>
using namespace std;

int main()
{
    struct Story
    {
        int x1, y1, x2, y2, area;

        Story (int x1, int y1, int x2, int y2)
        : x1{ x1 }, y1{ y1 }, x2{ x2 }, y2{ y2 }, area{ (y2 - y1) * (x2 - x1) }
        {}
    };

    int n;

    while (cin >> n && n != 0)
    {
        vector<Story> s;

        for (int i = 0 ; i < n; ++i)
        {
            int w, h, x, y; cin >> w >> h >> x >> y;
            s.emplace_back(x, y, x + w, y + h); // bl tr
        }

        vector<int> ol(n, 0);

        for (int i = 0 ; i < n ; ++i)
        {
            for (int j = i + 1 ; j < n; ++j)
            {
                auto& s1 = s[i];
                auto& s2 = s[j];

                if ((max(s1.x1, s2.x1) < min(s1.x2, s2.x2)) && (max(s1.y1, s2.y1) < min(s1.y2, s2.y2)))
                {
                    ol[i] |= (1 << j);
                    ol[j] |= (1 << i);
                }
            }
        }

        long long best = 0;

        auto gen = [&](int chose, int id, long long area, auto&& self) -> void
        {
            if (id == n)
            {
                best = max(best, area);
                return;
            }

            self(chose, id + 1, area, self);

            if (ol[id] & chose)
            {
            }
            else
            {
                chose |= (1 << id);
                self(chose, id + 1, area + s[id].area, self);
            }
        };

        gen(0, 0, 0, gen);

        cout << best << '\n';
    }
}
