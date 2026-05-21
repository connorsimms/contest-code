#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> target = {"ABCD", "EFGH", "IJKL", "MNO."};

    unordered_map<char, int> row, col;

    for (int i = 0 ; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            row[target[i][j]] = i;
            col[target[i][j]] = j;
        }
    }

    int sum = 0;
    for (int i = 0 ; i < 4; ++i)
    {
        for (int j = 0 ; j < 4; ++j)
        {
            char l; cin >> l;
            
            if (l == '.') continue;

            sum += abs(row[l] - i) + abs(col[l] - j);
        }
    }

    cout << sum << '\n';
}
