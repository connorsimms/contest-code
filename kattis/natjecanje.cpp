#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, S, R; cin >> N >> S >> R;
    int dmg = 0, rsv = 0;

    int hasBoat = (1 << N) - 1;

    for (int i = 0 ; i < S; ++i)
    {
        int x; cin >> x; 
        dmg |= (1 << (x - 1));
        hasBoat ^= (1 << (x - 1));
    }

    for (int i = 0 ; i < R; ++i)
    {
        int x; cin >> x; 
        rsv |= (1 << (x - 1));
    }

    int best = __builtin_popcount(hasBoat);

    int usedOwn = dmg & rsv;

    hasBoat += usedOwn;
    dmg -= usedOwn;
    rsv -= usedOwn;

    auto gen = [&](int hb, int d, int r, int id, auto&& self) -> void
    {
        if (id == N)
        {
            if (__builtin_popcount(hb) > best)
            {
                best = __builtin_popcount(hb);
            }
            return;
        }

        if (r & (1 << id))
        {
            if (id + 1 < N && (d & (1 << (id + 1))))
            {
                self(hb + (1 << (id + 1)), d - (1 << (id + 1)), r - (1 << id), id + 1, self);
            }

            if (id - 1 >= 0 && (d & (1 << (id - 1))))
            {
                self(hb + (1 << (id - 1)), d - (1 << (id - 1)), r - (1 << id), id + 1, self);
            }
        }

        self(hb, d, r, id + 1, self);
    };

    gen(hasBoat, dmg, rsv, 0, gen);

    cout << N - best << '\n';
}
