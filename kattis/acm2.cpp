#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, p; cin >> N >> p;

    vector<int> m;

    int pen;

    for (int i = 0; i < N; ++i)
    {
        if (i == p) 
        {
            cin >> pen; 
            if (pen > 300)
            {
                cout << "0 0\n";
                return 0;
            }
            continue;
        }

        int x; cin >> x; m.push_back(x);
    }

    sort(m.begin(), m.end());

    int t = pen;
    int cnt = 1;

    for (auto x : m)
    {
        if (t + x > 300) break;

        ++cnt;
        t += x;
        pen += t;
    }
    
    cout << cnt << " " << pen << '\n';
}
