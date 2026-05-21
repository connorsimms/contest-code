#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    int r, c, iter=0;
    while (cin >> r >> c && r != 0 && c != 0)
    {
        if (iter++) cout << '\n';

        vector<string> grid(c, string(r, ' '));

        for (int i = 0 ; i < r; ++i)
        {
            for (int j = 0 ; j < c; ++j)
            {
                cin >> grid[j][i];
            }
        }

        stable_sort(grid.begin(), grid.end(), [](auto A, auto B) {

            transform(A.begin(), A.end(), A.begin(), [](auto c) { return tolower(c); });
            transform(B.begin(), B.end(), B.begin(), [](auto c) { return tolower(c); });

            return A < B;
        });

        for (int i = 0 ; i < r; ++i)
        {
            for (int j = 0 ; j < c ; ++j)
            {
                cout << grid[j][i];
            }
            cout << '\n';
        }
    }
}
