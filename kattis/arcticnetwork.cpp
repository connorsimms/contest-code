#include <bits/stdc++.h>

using namespace std;

int kruskal(int V, int E, vector<tuple<int,int,int>>& edges)
{
    vector<int> parent(V);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> find_set = [&](int v) -> int {
	if(v == parent[v]) {
	    return v;
	} else {
	    parent[v] = find_set(parent[v]);
	    return parent[v];
	}
    };

    function <void(int,int)> unite_sets = [&](int a, int b) -> void {
	a = find_set(a);	
	b = find_set(b);	
	if(a != b) { parent[b] = a; }
    };

    sort(edges.begin(), edges.end());

    int minDist = 0;
    int edgesUsed = 0;

    for(const auto& edge: edges)
    {
	int weight = get<0>(edge);
	int v1 = get<1>(edge);
	int v2 = get<2>(edge);

	if(find_set(v1) != find_set(v2))
	{
	    minDist = max(minDist, weight);
	    unite_sets(v1, v2);
	    if( ++edgesUsed == E) { break; }
	}
    }

    return minDist;
}

int main()
{
    int N;
    cin >> N;
    for(int c = 0 ; c < N ; ++c)
    {
	int S, P;
	cin >> S >> P;
	
	vector<pair<int,int>> outpost(P);

	for(int i = 0 ; i < P ; ++i)
	{
	    cin >> outpost[i].first >> outpost[i].second; 
	}

	vector<tuple<int,int,int>> edges;

	for(int i = 0 ; i < P ; ++i)
	{
	    for(int j = i + 1 ; j < P ; ++j)
	    {
		int dx = outpost[i].first - outpost[j].first;
		int dy = outpost[i].second - outpost[j].second;
		int dist = dx * dx + dy * dy;
		edges.emplace_back(dist, i, j);
	    }
	}

	int ans = kruskal(P, P - S, edges); // S satellite channels will connect S outposts,
					    // P - S outposts need P - S - 1 edges,
					    // +1 to connect remaining S outposts with satellite channels

	cout << fixed << setprecision(2) << sqrt(ans) << '\n';
    }
    return 0;
}
