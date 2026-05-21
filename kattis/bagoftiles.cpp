#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int G; cin >> G;
    for (int g = 0 ; g < G; ++g)
    {
        int M, N, T;

        cin >> M;
        vector<int> l(M);

        int total = 0;

        for (int m = 0 ; m < M; ++m)
        {
            cin >> l[m]; 
            total += l[m];
        }

        cin >> N >> T;

        long long possible = 1;
        int k = min(N, M - N); 

        for (int i = 1; i <= k; ++i) {
            possible = possible * (M - i + 1) / i;
        }

        vector<vector<int>> memo(N + 1, vector<int>(T + 1, -1));

        memo[0][0] = 1;

        for (int i = 0 ; i < M ; ++i)
        {
            for (int t = T - l[i] ; t >= 0 ; --t)
            {
                for (int n = N - 1 ; n >= 0 ; --n)
                {
                    if (memo[n][t] == -1) continue;

                    if (memo[n + 1][t + l[i]] == -1) memo[n + 1][t + l[i]] = 0;

                    memo[n + 1][t + l[i]] += memo[n][t];
                }
            }
        }

        if (memo[N][T] == -1) memo[N][T] = 0;

        int win = memo[N][T];

        cout << "Game " << g + 1 << " -- ";
        cout << win;
        cout << " : ";
        cout << possible - win << '\n';
    }
}
