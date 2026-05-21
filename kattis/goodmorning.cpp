#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> board = {{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {-1, 0, -1}
    }};

    int best = 0;
    int target;

    auto gen = [&](int r, int c, int sum, auto&& self) {
        if (r > 3) return;
        if (c > 2) return;
        if (board[r][c] == -1) return;

        // don't press
        self(r + 1, c, sum, self);
        self(r, c + 1, sum, self);

        while (sum < target + board[r][c])
        {
            sum = sum * 10 + board[r][c];

            self(r + 1, c, sum, self);
            self(r, c + 1, sum, self);

            if (abs(target - sum) < abs(target - best))
            {
                best = sum;
            }

            if (sum == 0) return;
        }
    };

    int T; cin >> T;
    while (T--)
    {
        cin >> target;
        best = 0;

        gen(0, 0, 0, gen);

        cout << best << '\n';
    }
}
