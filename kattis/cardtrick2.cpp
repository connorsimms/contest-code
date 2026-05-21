#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;

        if (n == 1) 
        {
            cout << 1 << '\n';
            continue;
        }

        vector<int> v(n);

        queue<int> q;

        for (int i = 0 ; i < n; ++i)
        {
            q.push(i);
        }

        int c = 1;
        while(!q.empty())
        {
            for (int i = 0 ; i < c; ++i)
            {
                int x = q.front();
                q.pop();
                q.push(x);
            }
            
            v[q.front()] = c++;
            q.pop();
        }

        for (auto x : v)
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
}
