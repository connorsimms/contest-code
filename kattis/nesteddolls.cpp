#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;

        vector<pair<int,int>> dolls;

        for (int i = 0 ; i < n ; ++i)
        {
            int w, h; cin >> w >> h;
            dolls.emplace_back(w, h);
        }

        sort(dolls.begin(), dolls.end(), [](const auto& a, const auto& b)
             {
                if (a.first == b.first) return a.second < b.second;
                return a.first > b.first;
             });

        vector<int> lis(n, 0);
        int k = 0;

        for (auto [_, x]: dolls)
        {
            auto pos = upper_bound(lis.begin(), lis.begin()+k, x);
            int idx = pos - lis.begin();

            lis[idx] = x;
            if (idx == k) ++k;
        }

        cout << k << '\n';
    }
}
