#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int H, W, N, M; cin >> H >> W >> N >> M;

    vector<vector<int>> image(H, vector<int>(W));
    for (int i = 0 ; i < H; ++i)
    {
        for (int j = 0 ; j < W; ++j)
        {
            cin >> image[i][j];
        }
    }

    vector<vector<int>> mat(N, vector<int>(M));
    for (int i = 0 ; i < N; ++i)
    {
        for (int j = 0 ; j < M; ++j)
        {
            cin >> mat[i][j];
        }
    }

    reverse(mat.begin(), mat.end());
    for (auto& r : mat)
    {
        reverse(r.begin(), r.end());
    }

    vector<vector<int>> res(H - N + 1, vector<int>(W - M + 1, 0));

    for (int r = 0 ; r <= H - N; ++r)
    {
        for (int c = 0 ; c <= W - M; ++c)
        {
            for (int i = 0 ; i < N; ++i)
            {
                for (int j = 0 ; j < M; ++j)
                {
                    res[r][c] += mat[i][j] * image[r + i][c + j];
                }
            }
        }
    }

    for (auto r : res)
    {
        for (auto c: r)
        {
            cout << c << " ";
        }
        cout << '\n';
    }
}
