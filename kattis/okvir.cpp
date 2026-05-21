#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int M, N; cin >> M >> N;
    int U, L, R, D; cin >> U >> L >> R >> D;

    vector<string> out = vector(M + U + D, string(N + L + R, ' '));

    for (int i = 0 ; i < M + U + D; ++i)
    {
        for (int j = 0 ; j < N + L + R; ++j)
        {
            out[i][j] = ((i + j) % 2 == 0) ? '#' : '.';
        }
    }

    for (int i = U ; i < U + M ; ++i)
    {
        string word;
        cin >> word;
        for (int j = L; j < L + N; ++j)
        {
            out[i][j] = word[j - L];
        }
    }

    for (auto r : out)
    {
        cout << r << '\n';
    }
}
