#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int t; cin >> t;

    while (t--)
    {
        int r, c, n; cin >> r >> c >> n;

        vector<vector<char>> grid(r, vector<char>(c));
        vector<vector<char>> next(r, vector<char>(c));
        for (int i = 0 ; i < r ; ++i)
        {
            for (int j = 0 ; j < c ; ++j)
            {
                cin >> grid[i][j];
                next[i][j] = grid[i][j];
            }
        }

        unordered_map<char, int> mtoi;
        mtoi['S'] = 0;
        mtoi['R'] = 1;
        mtoi['P'] = 2;

        while (n--)
        {
            for (int i = 0 ; i < r ; ++i)
            {
                for (int j = 0 ; j < c ; ++j)
                {
                    next[i][j] = grid[i][j];
                }
            }

            for (int i = 0 ; i < r ; ++i)
            {
                for(int j = 0 ; j < c; ++j)
                {
                    int curr = mtoi[ grid[i][j] ];
                    if (j < c - 1) {
                        int right = mtoi[ grid[i][j + 1] ];
                        if ( curr   == ((right  + 1) % 3) ) { next[i][j + 1] = grid[i][j]; }
                        if ( right  == ((curr   + 1) % 3) ) { next[i][j] = grid[i][j + 1]; }
                    }
                    if (i < r - 1) {
                        int down = mtoi[ grid[i + 1][j] ];
                        if ( curr   == ((down   + 1) % 3) ) { next[i + 1][j] = grid[i][j]; }
                        if ( down   == ((curr   + 1) % 3) ) { next[i][j] = grid[i + 1][j]; }
                    }
                }
            }
            auto temp = grid;
            grid = next;
            next = temp;
        }

        for (auto row: grid)
        {
            for (auto cell: row)
            {
                cout << cell;
            }
            cout << '\n';
        }
        if (t > 0) { cout << '\n'; }
    }
}

