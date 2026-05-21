#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int R, S, K; cin >> R >> S >> K;

    vector<vector<int>> fcount(R, vector(S, 0)); 
    vector<vector<char>> out(R, vector(S, '.')); 

    for (int i = 0 ; i < R; ++i)
    {
        for (int j = 0 ; j < S; ++j)
        {
            cin >> out[i][j];

            if (out[i][j] == '*') { ++fcount[i][j]; }

            if (j > 0 ) fcount[i][j] += fcount[i][j-1]; 
        }
    }

    int ans = 0;
    int ansi = -1;
    int ansj = -1;

    for (int i = 0 ; i < R - K + 1 ; ++i)
    {
        for ( int j = 0 ; j < S - K + 1; ++j)
        {
            int sum = 0;
            // sum from (i + 1, j + 1) to (i + K - 2, j + K - 2)
            for (int k = 1; k < K - 1; ++k)
            {
                sum += fcount[i + k][j + K - 2] - fcount[i + k][j];
            }
            if (sum > ans) 
            {
                ans = sum;
                ansi = i;
                ansj = j;
            }
        }
    }
    
    out[ansi][ansj] = '+';
    out[ansi+K-1][ansj] = '+';
    out[ansi][ansj+K-1] = '+';
    out[ansi+K-1][ansj+K-1] = '+';

    for (int i = 1; i < K - 1 ; ++i)
    {
        out[ansi + i][ansj] = '|';
        out[ansi][ansj + i] = '-';
        out[ansi + K - 1][ansj + i] = '-';
        out[ansi + i][ansj + K - 1] = '|';
    }

    cout << ans << '\n';

    for (auto r : out)
    {
        for (auto c : r)
        {
            cout << c;
        }
        cout << '\n';
    }
}
