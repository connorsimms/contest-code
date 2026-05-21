#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        vector<int> v(n);

        for (int i = 0 ; i < n ; ++i)
        {
            cin >> v[i];
        }
        
        vector<int> res;
        unordered_map<int, int> par;

        for (int i = 0 ; i < n ; ++i)
        {
            auto pos = lower_bound(res.begin(), res.end(), v[i]);
            int idx = pos - res.begin();

            if (idx == res.size())
            {
                res.push_back(v[i]);
                par[res.back()] = idx ? res[idx - 1] : -1; 
            }
            else
            {
                res[idx] = v[i];
                par[v[i]] = idx ? res[idx - 1] : -1;
            }
        }

        vector<int> ans;
        int curr = res.back();
        while (curr != -1)
        {
            ans.push_back(curr);
            curr = par[curr];
        }
        reverse(ans.begin(), ans.end());

        cout << ans.size();
        for (auto x : ans) { cout << " " << x; }
        cout << '\n';
    }
}
