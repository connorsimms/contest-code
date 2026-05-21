#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M; cin >> N >> M;
    vector<vector<int>> P(N, vector<int>(M));
    for (int i = 0 ; i < N; ++i)
    {
        for (int j = 0 ; j < M; ++j)
        {
            cin >> P[i][j];
        }
    }

    vector<vector<int>> T(N, vector<int>(M));
    T[0][0] = P[0][0];
    for (int i = 1 ; i < M; ++i)
    {
        T[0][i] = P[0][i] + T[0][i-1]; 
    }

    for (int i = 1; i < N; ++i)
    {
        T[i][0] = T[i - 1][0] + P[i][0];
        for (int j = 1 ; j < M; ++j)
        {
            T[i][j] = max(T[i - 1][j], T[i][j - 1]) + P[i][j];
        }
    }

    for (int i = 0 ; i < N ; ++i)
    {
        cout << T[i].back() << " ";
    }
    cout << '\n';
}
