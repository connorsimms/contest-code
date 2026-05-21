#include <bits/stdc++.h>

using namespace std;

int ans = 0;

void longestDFS(const vector<vector<int>>& adj, int current, int currLen, int visited)
{
    for(auto next: adj[current])
    {
	if(next == 0)
	{
	    ans = max(ans, currLen);	    
	} else {
	    if((visited & (1 << next)) == 0)
	    {
		int newVisited = (visited | (1 << next));
		longestDFS(adj, next, currLen + 1, newVisited);
	    }
	}
    }
    return;
}

int main()
{
    int n, m;
    while(cin >> n && n != 0)
    {
	ans = 1;
	vector<vector<int>> adj(n);

	cin >> m;

	for(int i = 0 ; i < m ; ++i)
	{
	    int a, b;
	    cin >> a >> b;
	    
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}

	longestDFS(adj, 0, 1, 1);

	cout << ans << '\n';
    }
}
