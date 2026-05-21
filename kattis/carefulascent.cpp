#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y; cin >> x >> y;

    int n; cin >> n;

    vector<tuple<int,int,double>> field;

    for (int i = 0; i < n; ++i)
    {
        int l, u; double f; cin >> l >> u >> f;
        field.emplace_back(l, u, f);
    }

    sort(field.begin(), field.end());

    int curr = 0;
    int idx = 0;

    double val = 0.0;

    while (curr != y)
    {
        if (idx == n)
        {
            val += (y - curr);
            break;
        }

        const auto& [l, u, f] = field[idx];

        if (l == curr)
        {
            val += (u - l) * f;
            curr = u;
            ++idx;
        }
        else
        {
            val += (l - curr);
            curr = l;
        }
    }

    cout << fixed << setprecision(7) << x / val << '\n';
}
