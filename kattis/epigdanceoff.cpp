#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m));

    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < m ; ++j)
        {
            cin >> g[i][j];        
        }
    }

    bool per = false;
    int sep = 0;
    for (int c = 0 ; c < m; ++c)
    {
        bool empty = true;
        for (int r = 0 ; r < n ; ++r)
        {
            if (g[r][c] == '$') empty = false;
        }
        sep += (empty == true);
    }
    cout << sep + 1 << '\n';
}
