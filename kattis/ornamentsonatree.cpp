#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> weight(N);
    vector<int> limit(N, K);

    for(int i = 0; i < N; ++i)
    {
	cin >> weight[i];
	
	if(weight[i] != -1) { limit[i] -= weight[i]; }

	if(weight[i] > K) { cout << -1 << '\n'; return 0; }
    }

    vector<vector<int>> adj(N);
    vector<int> degree(N);

    for(int i = 0 ; i < N-1; ++i)
    {
	int a, b;
	cin >> a >> b;
	--a; --b;

	if(weight[a] != -1)
	{
	    limit[b] -= weight[a];
	}

	if(weight[b] != -1)
	{
	    limit[a] -= weight[b];
	}

	adj[a].push_back(b);
	adj[b].push_back(a);

	++degree[a];
	++degree[b];
    }

    for(auto x: limit) { if(x < 0) { cout << "-1\n"; return 0; } }

    queue<int> q;

    for(int i = 0 ; i < N; ++i)
    {
	if(degree[i] == 1) { q.push(i); }
    }

    while(!q.empty())
    {
	int f = q.front();
	//cout << f + 1 << '\n';
	degree[f] = 0;
	q.pop();

	for(auto next: adj[f])
	{
	    if(--degree[next] == 1)
	    {
		if(weight[f] == -1)
		{
		    weight[f] = min(limit[next], limit[f]);
		    limit[next] -= weight[f];
		    //cout << f + 1 << " is " << weight[f] << '\n';
		}
		q.push(next);	
	    }
	}
    }

    weight[0] = limit[0];
    int ans = 0;

    for(int i = 0 ; i < N; ++i)
    {
	if(weight[i] == -1) { weight[i] = 0; }
	//cout << i + 1 << " " << weight[i] << '\n';
	ans += weight[i];
    }

    cout << ans << '\n';
}
