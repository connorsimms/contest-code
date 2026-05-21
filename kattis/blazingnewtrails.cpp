#include <bits/stdc++.h>

using namespace std;

constexpr long long INF = 1e15;

int n, m, k, w;

pair<long long,int> kruskal(vector<tuple<long long,bool,int,int>>& original_edges, vector<bool>& special, long long pen)
{
    int V = n;

    auto edges = original_edges;

    vector<int> parent(V);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> find_set = [&](int v) {
	if(parent[v] == v) { 
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

    for(auto& edge: edges)
    {
	if(!get<1>(edge))
	{
	    get<0>(edge) += pen;
	}
    }
    
    sort(edges.begin(), edges.end());

    long long totalCost = 0;
    int edgesUsed = 0;
    int specialUsed = 0;

    for(const auto& edge: edges)
    {
	long long weight = get<0>(edge);
	bool spec = !get<1>(edge);
	int v1 = get<2>(edge);
	int v2 = get<3>(edge);

	if(find_set(v1) != find_set(v2))
	{
	    unite_sets(v1, v2);
	    totalCost += weight;

	    if(spec) { ++specialUsed; }

	    if(++edgesUsed == V - 1)
	    {
		break;
	    }
	}
    }

    if(edgesUsed != V - 1) { return make_pair(-1,-1); }

    int x = find_set(0);
    for(int i = 1 ; i < parent.size(); ++i)
    {
	if(find_set(i) != x)
	{
	    return make_pair(-1,-1);
	}
    }

    return make_pair(totalCost, specialUsed);
}

int main()
{
    cin >> n >> m >> k >> w;

    vector<bool> special(n);

    for(int i = 0 ; i < k ; ++i)
    {
	int s;
	cin >> s;
	--s;
	special[s] = true;
    }

    vector<tuple<long long,bool,int,int>> edges;

    for(int i = 0 ; i < m ; ++i)
    {
	int a, b; 
	long long c;
	cin >> a >> b >> c;
	--a; --b;

	edges.emplace_back(c, special[a] == special[b], a, b);
    }

    long long lower = -1e18;
    long long upper = 1e18;

    while(lower + 1 < upper)
    {
        long long mid = (lower + upper) / 2;	
        auto res = kruskal(edges, special, mid);

	if(res.second >= w) {
	    lower = mid;
	} else {
	    upper = mid;
	}
    }

    auto fin = kruskal(edges, special, lower);

    if(fin.second >= w) { cout << fin.first - lower * w << '\n'; } 
    else { cout << "-1\n"; }
}
