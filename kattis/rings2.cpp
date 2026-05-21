#include <iostream>
#include <array>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m, '.'));
    vector<vector<int>> ring(n, vector<int>(m, 0));
    vector<vector<bool>> seen(n, vector<bool>(m));

    queue<pair<int,int>> q;

    int numRings = 0;

    for (int i{0} ; i < n ; ++i)
    {
        for (int j{0}; j < m ; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '.')
            {
                q.emplace(i, j);
            }
        }
    }

    for (int i{0}; i < n; ++i)
    {
        if (grid[i][0] == 'T') 
        {
            q.emplace(i, 0);
            ring[i][0] = 1;
            seen[i][0] = true;
        }

        if (grid[i][m - 1] == 'T') 
        {
            q.emplace(i, m - 1);
            ring[i][m - 1] = 1;
            seen[i][m - 1] = true;
        }
    }

    for (int i{0}; i < m; ++i)
    {
        if (grid[0][i] == 'T') 
        {
            q.emplace(0, i);
            ring[0][i] = 1;
            seen[0][i] = true;
        }

        if (grid[n - 1][i] == 'T') 
        {
            q.emplace(n - 1, i);
            ring[n - 1][i] = 1;
            seen[n - 1][i] = true;
        }
    }

    array<int, 4> dr = {0, 0, -1, 1};
    array<int, 4> dc = {-1, 1, 0, 0};

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        for (int i{0}; i < 4; ++i)
        {
            if (r + dr[i] < 0 || r + dr[i] >= n) continue;
            if (c + dc[i] < 0 || c + dc[i] >= m) continue;

            if (grid[r + dr[i]][c + dc[i]] != 'T') continue;

            if (!seen[r + dr[i]][c + dc[i]])
            {
                ring[r + dr[i]][c + dc[i]] = ring[r][c] + 1;
                seen[r + dr[i]][c + dc[i]] = true;
                q.emplace(r + dr[i], c + dc[i]);
                numRings = max(numRings, ring[r][c] + 1);
            }
        }
    }

    int w = (numRings < 10) ? 2 : 3;
    string empty(w, '.');

    for (auto r : ring)
    {
        for (auto c: r)
        {
            if (!c) 
            {
                cout << empty;
                continue;
            }

            for (int i = 0 ; i < w - c / 10 - 1; ++i) cout << '.';

            cout << c;
        }
        cout << '\n';
    }
}
