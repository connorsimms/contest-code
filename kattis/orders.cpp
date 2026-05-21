#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> c(n);
    for (int i = 0 ; i < n; ++i)
    {
        cin >> c[i];
    }

    int m; cin >> m;

    for (int i = 0 ; i < m ; ++i)
    {
        int total; cin >> total;
        
        vector<int> mem(total + 1, -1);

        for (int j = c[0] ; j < total + 1; j += c[0]) // all reachable using first item
        {
            mem[j] = 0;
        }

        for (int j = 1 ; j < n ; ++j)
        {
            int val = j;
            for (int k = c[j] ; k < total + 1; k += c[j])
            {
                // already discovered, everything from here is ambiguous
                if (mem[k] != -1) val = -2; 

                mem[k] = val;
            }


            for (int cost = 0 ; cost < total + 1 - c[j]; ++cost)
            {
                if (mem[cost] == -1) continue; 

                // spread ambiguity
                if (mem[cost] == -2) { mem[cost + c[j]] = -2; }

                // discover new total
                if (mem[cost + c[j]] == -1) mem[cost + c[j]] = j;

                // already discovered by previous items
                else if (mem[cost + c[j]] != j) { mem[cost + c[j]] = -2; }
            }
        }

        if (mem[total] == -2) { cout << "Ambiguous\n"; continue; }
        if (mem[total] == -1) { cout << "Impossible\n"; continue; }

        int rem = total;
        multiset<int> ans;
        while (rem > 0)
        {
            ans.insert(mem[rem] + 1);
            rem -= c[mem[rem]];
        }
        for (auto x: ans)
        {
            cout << x << " ";
        }
        cout << '\n';
    }
}
