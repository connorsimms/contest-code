#include <iostream>
#include <set>
#include <functional>
#include <vector>
using namespace std;

int main()
{
    int C, n;
    while (cin >> C)
    {
        cin >> n;

        vector<vector<int>> mem(n, vector<int>(C + 1, -1));

        vector<int> w(n);
        vector<int> v(n);
    
        for (int i = 0 ; i < n ; ++i)
        {
            cin >> v[i] >> w[i];
        }

        int max = 0;

        auto solve = [&](int item, int rem, auto&& self) -> int {
            if (item == n || rem == 0) return 0;

            int& ans = mem[item][rem];

            if (ans != -1) return ans;
            
            if (w[item] > rem) return ans = self(item + 1, rem, self);

            int inc = v[item] + self(item + 1, rem - w[item], self); 
            int exc = self(item + 1, rem , self);

            if (inc > exc)
            {
                ans = inc;
            }
            else
            {
                ans = exc;
            }

            return ans;
        };

        
        int sol = solve(0, C, solve);

        //for (auto r : mem)
        //{
        //    for (auto c : r)
        //    {
        //        cout << c << '\t';
        //    }
        //    cout << '\n';
        //}

        vector<int> ans;
        int rem = C;

        for (int i = 0 ; i < n - 1; ++i)
        {
            if (w[i] > rem) continue;

            if ((mem[i][rem] == mem[i + 1][rem - w[i]] + v[i]) ||
                (mem[i + 1][rem - w[i]] == -1 && mem[i][rem] == v[i]))
            {
                ans.push_back(i);
                rem -= w[i];
            }
        }

        if (mem[n-1][rem] == v[n-1])
        {
            ans.push_back(n-1);
            rem -= w[n-1];
        }

        cout << ans.size() << '\n';
        if (!ans.empty())
        {
            for (int i = 0 ; i < ans.size() - 1; ++i)
            {
                cout << ans[i] << ' ';
            }
            cout << ans.back() << '\n';
        }
    }
}
