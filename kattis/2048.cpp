#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()
{
    // l, u, r, d
    array<array<int, 4>, 4> grid;

    for (int i = 0 ; i < 4 ; ++i)
    {
        for (int j = 0 ; j < 4 ; ++j)
        {
            cin >> grid[i][j];
        }
    }

    int dir; cin >> dir;

    if (dir == 0) { for (auto& r: grid) { reverse(r.begin(), r.end()); } }
    if (dir == 1 || dir == 3) 
    {
        for (int i = 0 ; i < 4; ++i)
        {
            for (int j = i + 1; j < 4; ++j)
            {
                swap(grid[i][j], grid[j][i]);
            }
        }
    }
    if (dir == 1) { for (auto& r: grid) { reverse(r.begin(), r.end()); } }

    for (int i = 0 ; i < 4 ; ++i)
    {
        for (int j = 2 ; j >= 0; --j)
        {
            int& curr = grid[i][j];
            int& next = grid[i][j + 1];

            if (curr == 0) continue; 

            if (next == 0) { swap(next, curr); j = 2; }

        }
    }

    for (int i = 0 ; i < 4 ; ++i)
    {
        for (int j = 2 ; j >= 0; --j)
        {
            int& curr = grid[i][j];
            int& next = grid[i][j + 1];

            if (curr == 0) continue; 

            if (next == curr) { next *= 2; curr = 0; }
        }
    }

    for (int i = 0 ; i < 4 ; ++i)
    {
        for (int j = 2 ; j >= 0; --j)
        {
            int& curr = grid[i][j];
            int& next = grid[i][j + 1];

            if (curr == 0) continue; 

            if (next == 0) { swap(next, curr); j = 2; }
        }
    }

    if (dir == 1) { for (auto& r: grid) { reverse(r.begin(), r.end()); } }
    
    if (dir == 1 || dir == 3) 
    {
        for (int i = 0 ; i < 4; ++i)
        {
            for (int j = i + 1; j < 4; ++j)
            {
                swap(grid[i][j], grid[j][i]);
            }
        }
    }

    if (dir == 0) { for (auto& r: grid) { reverse(r.begin(), r.end()); } }
    
    for (auto r : grid)
    {
        for (auto c: r)
        {
            cout << c << " ";
        }
        cout << '\n';
    }
}
