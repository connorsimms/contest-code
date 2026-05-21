#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,int>> r;
    for (int i = 0 ; i < 3; ++i) { int x, y; cin >> x >> y; r.emplace_back(x, y); }

    sort(r.begin(), r.end());

    do
    {
        bool valid = true;
        auto [x1, y1] = r.front();

        for (int i = 1 ; i <= 2; ++i)
        {
            auto [x2, y2] = r[i];

            if (x1 == x2)
            {
                y1 += y2;
            }

            else if (y1 == x2)
            {
                x1 += y2;
            }

            else if (x1 == y2)
            {
                y1 += x2;
            }

            else if (y1 == y2)
            {
                x1 += x2;
            }

            else
            {
                valid = false;
                break;
            }
        }

        if (valid && x1 == y1) 
        {
            cout << "YES\n";
            return 0;
        }
    } while (next_permutation(r.begin(), r.end()));

    cout << "NO\n";
}
