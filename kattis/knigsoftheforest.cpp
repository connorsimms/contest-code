#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    int k, n; cin >> k >> n;

    int y, p; cin >> y >> p;

    priority_queue<int> moose;
    vector<pair<int,int>> data;

    if (y == 2011) moose.push(p);
    else data.emplace_back(y, p);

    for (int i = 0 ; i < n + k - 2; ++i)
    {
        int year, power; cin >> year >> power;
        if (year == 2011)
        {
            moose.push(power);
        }
        else
        {
            data.emplace_back(year, power);
        }
    }

    sort(data.begin(), data.end());

    int lastYear = 2011;

    for (auto [year, power] : data)
    {
        if (moose.top() == p)
        {
            cout << lastYear << '\n';
            return 0;
        }

        moose.pop();
        moose.push(power);
        lastYear = year;
    }

    if (moose.top() == p) 
    {
        cout << lastYear << '\n';
        return 0;
    }

    cout << "unknown\n";
}
