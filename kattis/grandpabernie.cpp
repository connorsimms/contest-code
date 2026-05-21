#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    unordered_map<string, vector<int>> years;

    int n; cin >> n;
    for (int i = 0 ; i < n; ++i)
    {
        string country; cin >> country;
        int year; cin >> year;

        years[country].push_back(year);
    }

    for (auto& [country, v] : years)
    {
        sort(v.begin(), v.end());
    }

    int m; cin >> m;
    for (int i = 0 ; i < m ; ++i)
    {
        string country; cin >> country;
        int idx; cin >> idx;

        cout << years[country][idx - 1] << '\n';
    }
}

