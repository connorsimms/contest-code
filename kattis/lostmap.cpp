#include <bits/stdc++.h>

using namespace std;

void kruskal(int V, vector<tuple<int,int,int>>& edges)
{
    vector<int> parent(V + 1);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> find_set = [&](int v) {
	if(parent[v] == v) { return v; }
	else {
	    parent[v] = find_set(parent[v]);
	    return parent[v];
	}
    };

    function<void(int,int)> unite_sets = [&](int a, int b) {
	a = find_set(a);
	b = find_set(b);
	
	if(a != b) {
	    parent[b] = a; 
	}
    };

    sort(edges.begin(), edges.end());

    int edgesUsed = 0;

    for(const auto& edge: edges)
    {
	int dist = get<0>(edge);
	int v1 = get<1>(edge);
	int v2 = get<2>(edge);

	int a = find_set(v1);
	int b = find_set(v2);

	if(a != b) {
	    unite_sets(a, b);
	    cout << v1 << " " << v2 << '\n';
	    
	    if(++edgesUsed == V - 1) { break; }
	}
    }

    return;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    vector<tuple<int,int,int>> edges;

    for(int i = 1 ; i <= n ; ++i)
    {
	for(int j = 1 ; j <= n ; ++j)
	{
	    int dist;
	    cin >> dist;

	    if(i <= j) { continue; }

	    edges.emplace_back(dist, j, i);
	}
    }
    
    kruskal(n, edges);
}
