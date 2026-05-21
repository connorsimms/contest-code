#include <bits/stdc++.h>

using namespace std;

int V;

vector<long long> getClique(const vector<long long>& adj)
{
    vector<long long> cliques;
    for(long long subset = (1 << (V / 2)) ; subset < (1 << V) ; subset += (1 << (V / 2)))
    {
	bool isClique = true;
	for(int i = V / 2 ; i < V ; ++i)
	{
	    if((subset & (1LL << i)) != 0)
	    {
		if((adj[i] & subset) != (subset ^ (1LL << i)))
		{
		    isClique = false;
		    break;
		}
	    }
	}
	if(isClique)
	{
	    cliques.push_back(subset);
	}
    }
    return cliques;
}

void cliquePrecompute(const vector<long long>& adj, map<long long, int>& largest)
{
    auto latterCliques = getClique(adj);
    for(auto cli: latterCliques)
    {
	long long compatible = 0;
	for(int i = 0 ; i < V / 2; ++i)
	{
	    if((adj[i] & cli) == cli)
	    {
		compatible |= (1 << i);
	    }
	}
	largest[compatible] = max(largest[compatible], __builtin_popcountll(cli));
    }

    for(auto it = largest.rbegin(); it != largest.rend(); ++it)
    {
	long long subset = it->first;	
	for(int i = 0 ; i < V / 2 ; ++i)
	{
	    if((subset & (1 << i)) != 0)
	    {
		long long nextSub = subset ^ (1 << i);
		largest[nextSub] = max(largest[subset], largest[nextSub]);
	    }
	}
    }
}

int main()
{
    int E;
    cin >> V >> E;

    vector<long long> adj(V);
    map<long long, int> largest;

    for(int i = 0 ; i < E ; ++i)
    {
	int a, b;
	cin >> a >> b;

	adj[a] |= (1 << b);
	adj[b] |= (1 << a);
    }

    cliquePrecompute(adj, largest);

    int max_clique_size = 0;

    for(long long subset = 0 ; subset < (1 << (V / 2)); ++subset)
    {
	bool isClique = true;
	for(int i = 0 ; i < V / 2; ++i)
	{
	    if((subset & (1LL << i)) != 0)
	    {
		if((adj[i] & subset) != (subset ^ (1LL << i)))
		{
		    isClique = false;
		    break;
		}
	    }
	}
	if(isClique)
	{
	    max_clique_size = max(max_clique_size, __builtin_popcountll(subset) + largest[subset]);
	}
    }

    cout << max_clique_size << '\n';
}

