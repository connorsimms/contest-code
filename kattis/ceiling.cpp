#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;

    vector<int> v((1 << k)); 
    set<int> used;

    auto ins = [&](int idx, int val, auto&& self) {
        if (v[idx] == 0) { v[idx] = val; used.insert(idx); return; }

        if (val >= v[idx]) self(idx * 2 + 2, val, self);
        else self(idx * 2 + 1, val, self);
    };

    set<set<int>> seen;

    for (int i = 0; i < n; ++i)
    {
        v.assign(v.size(), 0);
        used.clear();

        for (int j = 0; j < k; ++j)
        {
            int x; cin >> x;

            ins(0, x, ins);
        }

        seen.insert(used);
    }

    cout << seen.size() << '\n';
}
