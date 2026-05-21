#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c; cin >> r >> c;

    vector<vector<char>> grid(r, vector<char>(c));

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> grid[i][j]; 
        }
    }

    vector<int> f(5, 0);

    for (int i = 0; i < r - 1; ++i)
    {
        for (int j = 0; j < c - 1; ++j)
        {
            int cars = 0;
            bool valid = true;

            for (int dr = 0; dr < 2; ++dr)
            {
                for (int dc = 0; dc < 2; ++dc)
                {
                    if (grid[i + dr][j + dc] == 'X')
                        ++cars;

                    if (grid[i + dr][j + dc] == '#')
                        valid = false;
                }
            }
            if (!valid) continue;

            ++f[cars];
        }
    }

    for (auto x : f)
    {
        cout << x << '\n';
    }
}
