#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    deque<int> t, q;

    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x; t.push_back(x);
    }

    for (int i = 0; i < m; ++i)
    {
        int x; cin >> x; q.push_back(x);
    }

    sort(t.begin(), t.end()); sort(q.begin(), q.end());

    int ans = 0;
    while (!t.empty() && !q.empty())
    {
        if (q.front() >= t.front())
        {
            ++ans;
            q.pop_front(); t.pop_front();
            continue;
        }
        else
        {
            q.pop_front();
        }
    }

    cout << ans << '\n';
}
