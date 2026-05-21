/*
* Run a multi-source Dijkstra using spider nodes as sources.
*
* Then run a modified dijkstra that only explores nodes with >= D distance
* to nearest spider node. Return true if distance between s and t is less than T.
*
* Binary search on this argument D and output maximum D.
*/
#include <bits/stdc++.h>

constexpr int INF = 1000000000;

using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, vector<int> spiders)
{
    vector<int> dist(adj.size(), INF); 

    set<pair<int,int>> q;

    for(auto s: spiders)
    {
	dist[s] = 0;
	q.emplace(0, s);
    }

    while(!q.empty())
    {
	int curr = q.begin()->second;
	q.erase(q.begin());

	for(auto edge: adj[curr])
	{
	    int next = edge.first;
	    int d = dist[curr] + edge.second;

	    if(d < dist[next])
	    {
		if(dist[next] != INF)
		{
		    q.erase({dist[next], next});
		}
		dist[next] = d;
		q.emplace(dist[next], next);
	    }
	}
    }

    return dist;
}

int s, t, T;

bool checkD(int D, const vector<int>& spiDist, const vector<vector<pair<int,int>>>& adj)
{
    vector<int> dist(adj.size(), INF);

    dist[s] = 0;

    if(spiDist[s] < D) { return false; }

    set<pair<int,int>> q;
    q.emplace(0, s);

    while(!q.empty())
    {
	int curr = q.begin()->second;
	q.erase(q.begin());

	for(const auto& edge: adj[curr])
	{
	    int next = edge.first;
	    int d = dist[curr] + edge.second;
	    int sd = spiDist[next];

	    if(d < dist[next] && sd >= D)
	    {
		if(dist[next] != INF)
		{
		    q.erase({dist[next], next});
		}
		dist[next] = d;
		q.emplace(dist[next], next);
	    }
	}
    }

    return dist[t] <= T;
}

int main()
{
    int N, M;
    cin >> N >> M >> T;

    vector<vector<pair<int,int>>> adj(N);

    for(int i = 0 ; i < M ; ++i)
    {
	int u, v, d;
	cin >> u >> v >> d;

	adj[u].emplace_back(v, d);	
	adj[v].emplace_back(u, d);	
    }

    cin >> s >> t;

    int K;
    cin >> K;
    
    vector<int> spiders(K);

    for(int i = 0 ; i < K ; ++i)
    {
	cin >> spiders[i];	
    }

    auto spiderDist = dijkstra(adj, spiders);

    int best = 0;

    int lower = 0;
    int upper = T;

    while(lower <= upper)
    {
	int mid = lower + (upper - lower) / 2;
	
	if(checkD(mid, spiderDist, adj)) {
	    best = max(best, mid);
	    lower = mid + 1;
	} else {
	    upper = mid - 1;
	}
    }

    cout << best << '\n';

}
