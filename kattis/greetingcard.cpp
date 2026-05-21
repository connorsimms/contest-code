#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <utility>
#include <unordered_set>
#include <cmath>
using namespace std;

int main()
{
    set<pair<int, int>> dxdy;

    for (int x = 0 ; x <= 2018; ++x)
    {
        int y = sqrt(2018 * 2018 - x * x);

        if (x * x + y * y == 2018 * 2018)
        {
            dxdy.emplace(x, y);
            dxdy.emplace(-x, y);
            dxdy.emplace(x, -y);
            dxdy.emplace(-x, -y);
        }
    }

    unordered_set<string> points;
    vector<pair<long long, long long>> pointData;

    int n; cin >> n;
    for (int i = 0 ; i < n ; ++i)
    {
        long long x, y; cin >> x >> y;
        string point = to_string(x) + ':' + to_string(y);
        points.insert(point);
        pointData.emplace_back(x,y);
    }

    long long ans = 0;

    for (auto [x,y] : pointData)
    {
        for (auto [dx, dy] : dxdy)
        {
            string point = to_string(x + dx) + ':' + to_string(y + dy);

            if (points.count(point))
            {
                ++ans;
            }
        }
    }

    cout << ans / 2 << '\n';
}
