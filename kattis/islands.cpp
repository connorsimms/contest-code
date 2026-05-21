#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T; cin >> T;

    for (int t = 1 ; t <= T; ++t)
    {
        int x; cin >> x;
        cout << t << " ";

        stack<int> s;

        int cnt = 0;

        for (int i = 0 ; i < 12; ++i)
        {
            int x; cin >> x;

            while (!s.empty() && x < s.top())
            {
                ++cnt;
                s.pop();
            }

            if (s.empty() || x > s.top()) 
            {
                s.push(x);
            }
        }

        cout << cnt << '\n';
    }
}
