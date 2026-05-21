#include <bits/stdc++.h>

using namespace std;

double kruskal(int V, vector<tuple<double,int,int>>& edges)
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

    function<void(int,int)> unite_sets = [&](int a, int b) {
	a = find_set(a);	
	b = find_set(b);	
	if(a != b) {
	    parent[b] = parent[a];
	}
    };

    sort(edges.begin(), edges.end());

    double totalDist = 0.0;
    int edgesUsed = 0;

    for(const auto& edge: edges)
    {
	auto dist = get<0>(edge);
	auto v1 = get<1>(edge);
	auto v2 = get<2>(edge);

	if(find_set(v1) != find_set(v2)) {
	    unite_sets(v1, v2);
	    totalDist += dist;
	    if(++edgesUsed == V - 1) { break; }
	}
    }

    return totalDist;
}

int main()
{
    int N;
    cin >> N;
    for(int c = 0 ; c < N ; ++c)
    {
	int n;
	cin >> n;
	
	vector<pair<double,double>> island(n);

	for(int i = 0 ; i < n ; ++i)
	{
	    cin >> island[i].first >> island[i].second; 
	}

	vector<tuple<double,int,int>> edges;

	for(int i = 0 ; i < n ; ++i)
	{
	    for(int j = i + 1 ; j < n ; ++j)
	    {
		double dx = island[i].first - island[j].first;
		double dy = island[i].second - island[j].second;
		double dist = sqrt(dx * dx + dy * dy);
		edges.emplace_back(dist, i, j);
	    }
	}

	double ans = kruskal(n, edges);

	cout << fixed << setprecision(6) << ans << '\n';
    }
    return 0;
}
