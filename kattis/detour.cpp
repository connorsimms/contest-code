#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1000000000;

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int s)
{
    vector<int> dist(adj.size(), INF); 

    dist[s] = 0;
    set<pair<int,int>> q;
    q.emplace(0, s);

    while(!q.empty())
    {
	int next = q.begin()->second;
	q.erase(q.begin());
	for(auto edge: adj[next])
	{
	    int v = edge.first;
	    int d = dist[next] + edge.second;

	    if(d < dist[v])
	    {
		if(dist[v] != INF)
		{
		    q.erase({dist[v], v});
		}
		dist[v] = d;
		q.emplace(dist[v], v);
	    }
	}
    }

    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0 ; i < m ; ++i)
    {
	int a, b, d;
	cin >> a >> b >> d;

	adj[a].emplace_back(b, d);
	adj[b].emplace_back(a, d);
    }

    auto amsDist = dijkstra(adj, 1);

    stack<int> st;
    st.push(0);
    unordered_map<int,int> backtrack;
    backtrack[1] = -1;
    unordered_map<int,bool> seen;

    while(!st.empty())
    {
	int t = st.top();
	st.pop();

	int avoid = -1;
	int minDist = INF;

	for(auto next: adj[t])
	{
	    if(amsDist[next.first] + next.second < minDist)
	    {
		avoid = next.first;
		minDist = amsDist[next.first] + next.second;
	    }
	}

	for(auto next: adj[t])
	{
	    if(!seen[next.first] && avoid != next.first)
	    {
		seen[next.first] = true;
		st.push(next.first);
		backtrack[next.first] = t;
	    }
	}
    }

    if(backtrack[1] == -1)
    {
	cout << "impossible\n";
    }
    else
    {
	vector<int> ans;
	int curr = 1;
	while(true)
	{
	    ans.push_back(curr);
	    if(curr == 0) { break; }
	    curr = backtrack[curr];
	}

	cout << ans.size() << " ";
	for(auto it = ans.rbegin(); it != ans.rend() ; ++it)
	{
	    cout << *it << " ";
	}
    }
}
