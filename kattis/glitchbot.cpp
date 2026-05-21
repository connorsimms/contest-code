#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int X, Y; cin >> X >> Y;    

    int n; cin >> n;
    
    vector<string> inst = {"Forward", "Left", "Right"};
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    vector<string> order(n);

    for (int i = 0 ; i < n ; ++i)
    {
        cin >> order[i];
    }

    for (int i = 0 ; i < n ; ++i)
    {
        for (auto c : inst)
        {
            if (c == order[i]) continue;

            int x = 0, y = 0;
            int dir = 0;

            for (int j = 0 ; j < n ; ++j)
            {
                string curr = (i == j) ? c : order[j];

                if (curr == "Forward") { x += dx[dir]; y += dy[dir]; }
                if (curr == "Left") { dir += 3; dir %= 4; }
                if (curr == "Right") { dir += 1; dir %= 4; }
            }

            if (x == X && y == Y)
            {
                cout << i + 1 << " " << c << '\n';
                return 0;
            }
        }
    }
}
