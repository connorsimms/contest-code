#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cout << "Test " << t << '\n';
        
        int R, C; cin >> R >> C;
        string junk; getline(cin, junk);

        string grid(R * C, 'x');

        for (int i = 0 ; i < R; ++i)
        {
            string line; getline(cin, line);
            for (int j = 0 ; j < C; ++j) grid[C * i + j] = line[j];
        }
        
        string temp(grid);

        for (int r = 0; r < R; ++r)
        {
            for (int c = 0; c < C; ++c)
            {
                temp[r * C + c] = grid[r * C + (C - 1 - c)];
            }
        }

        for (int r = 0; r < R; ++r)
        {
            for (int c = 0; c < C; ++c)
            {
                grid[r * C + c] = temp[(R - r - 1) * C + c];
            }
        }

        for (int r = 0 ; r < R; ++r)
        {
            cout << grid.substr(r * C, C) << '\n';
        }
    }
}
