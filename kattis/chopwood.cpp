#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> u(n), v(n);
    unordered_map<int, int> frq;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        frq[v[i]]++;
    }

    if (v.back() != n + 1)
    {
        cout << "Error\n"; return 0;
    }

    for (int i = 1; i <= n + 1; ++i)
    {
        if (!frq[i]) pq.push(i);
    }

    for (int i = 0 ; i < n; ++i)
    {
        u[i] = pq.top(); pq.pop();
        if(--frq[v[i]] == 0) pq.push(v[i]);
    }

        if (u[0] == n + 1)
        {
            cout << "Error\n"; return 0; 
        }

    set<pair<int, int>> seen;

    for (int i = 0 ; i < n; ++i)
    {
        if (seen.count(make_pair(min(u[i], v[i]), max(u[i], v[i]))))
        {
            cout << "Error\n";
            return 0;
        }
        
        seen.emplace(min(u[i], v[i]), max(u[i], v[i]));
    }

    for (auto x : u)
    {
        cout << x << '\n';
    }
}
