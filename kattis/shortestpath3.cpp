#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1000000000;

vector<int> bellman(int V, const vector<tuple<int,int,int>>& edges, int S)
{
    vector<int> dist(V, INF);

    dist[S] = 0;

    for(int i = 0 ; i < V - 1 ; ++i)
    {
	for(const auto& edge: edges)
	{
	    if(dist[get<0>(edge)] != INF) // finite dist
	    {
		dist[get<1>(edge)] = min(dist[get<1>(edge)], dist[get<0>(edge)] + get<2>(edge));
	    }
	}
    }

    for(const auto& edge: edges) // check if dist can be reduced more, implying negative weight cycle
    {
	if(dist[get<1>(edge)] != INF && dist[get<0>(edge)] + get<2>(edge) < dist[get<1>(edge)]) {
	    dist[get<1>(edge)] = -1 * INF; // set these to -infinity, propogate later
	}
    }

    return dist;
}

int main() {
    int n, m, q, s;

    bool first = true;

    while(cin >> n >> m >> q >> s && (n != 0 || m != 0 || q != 0 || s != 0))
    {
	if(!first) {cout << '\n';}
	first = false;

	vector<vector<int>> adj(n);
	vector<tuple<int,int,int>> edges;

	for(int i = 0 ; i < m ; ++i)
	{
	    int u, v, d;
	    cin >> u >> v >> d;

	    adj[u].push_back(v);
	    edges.emplace_back(u,v,d);
	}

	auto res = bellman(n, edges, s);

	queue<int> qu;
	unordered_map<int, bool> seen;

	for(int i = 0 ; i < n ; ++i)
	{
	    if(res[i] == -1 * INF)
	    {
		qu.push(i);
		seen[i] = true;
	    }
	}

	while(!qu.empty())
	{
	    int f = qu.front();
	    qu.pop();

	    for(auto next: adj[f])
	    {
		if(!seen[next])	
		{
		    res[next] = -1 * INF;
		    seen[next] = true;
		    qu.push(next);
		}
	    }
	}

	for(int i = 0 ; i < q; ++i)
	{
	    int query;
	    cin >> query;

	    auto x = res[query];

	    if(x == INF) {
		cout << "Impossible\n";	
	    } else if(x == INF * -1) {
		cout << "-Infinity\n";
	    } else {
		cout << x << '\n';
	    }
	}
    }
}
