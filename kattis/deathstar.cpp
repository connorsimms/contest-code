#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N; cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));

    for (int i = 0 ; i < N; ++i)
    {
       for (int j = 0 ; j < N; ++j)
        {
            cin >> grid[i][j];
        }
    }

    vector<int> res(N, 0);

    for (int i = 0 ; i < N ; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            res[i] |= grid[i][j];
            res[j] |= grid[i][j];
        }
    }

    for (auto x: res)
    {
        cout << x << " ";
    }
    cout << '\n';
}
