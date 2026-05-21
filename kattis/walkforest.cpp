#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9 + 1;

vector<int> dijkstra(const vector<vector<pair<int,int>>>& adj, int V)
{
    vector<int> dist(adj.size(), INF);

    dist[V] = 0;

    set<pair<int,int>> pq;

    pq.emplace(dist[V], V);

    while(!pq.empty())
    {
	int v = pq.begin()->second;	
	pq.erase(pq.begin());

	for(auto edge: adj[v])
	{
	    int next = edge.first;
	    int d = edge.second + dist[v];

	    if(d < dist[next])
	    {
		if(dist[next] != INF) { pq.erase({dist[next], next}); }

		dist[next] = d;
		pq.emplace(dist[next], next);
	    }
	}
    }
    
    return dist;
}

int main()
{
    int N, M;
    while(cin >> N && N != 0) {
	cin >> M;

	vector<vector<pair<int,int>>> adj(N);
	
	for(int i = 0 ; i < M ; ++i)
	{
	    int a, b, d;
	    cin >> a >> b >> d;
	    --a; --b;

	    adj[a].emplace_back(b, d);
	    adj[b].emplace_back(a, d);
	}

	vector<int> homeDist = dijkstra(adj, 1); // office is 0 and home is 1 0-indexing

	vector<int> num(N); // number of ways to get to vertex
	num[1] = 1;

	set<pair<int,int>> q; // prioritize closer nodes
	unordered_map<int, bool> seen;

	q.emplace(1, 1); // dist, vertex // start at home
	seen[1] = true;

	while(!q.empty())
	{
	    int f = q.begin()->second;
	    q.erase(q.begin());

	    for(auto edge: adj[f])
	    {
		int next = edge.first;

		if(homeDist[next] > homeDist[f])
		{
		    num[next] += num[f];
		    q.emplace(homeDist[next], next);
		}
	    }
	}
	cout << num[0] << '\n';
    }
}
