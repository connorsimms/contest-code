#include <bits/stdc++.h>

using namespace std;

int N, M;

int ans = 0;

int ctz128(__int128 n)
{
    unsigned long long lower = (unsigned long long)n;
    if(lower != 0)
    {
	return __builtin_ctzll(lower);
    }
	
    unsigned long long upper = (unsigned long long)(n >> 64);
    return __builtin_ctzll(upper) + 64;
}

void solve(const vector<__int128>& adj, __int128 clique, __int128 cand, __int128 proc)
{
    if(ans > 1000) { return; }

    if(cand == 0)
    {
	if(proc == 0)
	{
	    //cout << "maximal clique with size " << __builtin_popcount(clique) << '\n';
	    ans++;
	    return;
	} else {
	    return;
	}
    }
    int bestPivot = -1;
    int maxNeighbors = -1;

    __int128 pivotCand = cand | proc;
    while(pivotCand > 0)
    {
	int p = ctz128(pivotCand);
	int candNeighbors = __builtin_popcountll((unsigned long long)(cand & adj[p])) +
			    __builtin_popcountll((unsigned long long)((cand & adj[p]) >> 64));
	if(candNeighbors > maxNeighbors)
	{
	    maxNeighbors = candNeighbors;
	    bestPivot = p;
	}
	pivotCand ^= ((__int128)1 << p);
    }

    __int128 not_pivot_nei = (cand & ~adj[bestPivot]);
    __int128 tempCand = not_pivot_nei;

    while(tempCand > 0)
    {
	int i = ctz128(tempCand);
	__int128 ibit = ((__int128)1 << i);

	__int128 newClique = (clique | ibit);
	__int128 newCand = (cand & adj[i]);
	__int128 newProc = (proc & adj[i]);

	solve(adj, newClique, newCand, newProc);

	cand ^= ibit;
	proc |= ibit; 
	
	tempCand ^= ibit;
    }
    //cout << "trying clique with size " << __builtin_popcount(clique) << '\n';

    //for(int i = 0 ; i < N ; ++i)
    //{
    //    if((cand & (1 << i)) != 0)
    //    {
    //        __int128 newClique = (clique | (1 << i));
    //        __int128 newCand = (cand & adj[i]);
    //        __int128 newProc = (proc & adj[i]);

    //        solve(adj, newClique, newCand, newProc);

    //        cand ^= (1 << i);
    //        proc |= (1 << i);
    //    }
    //}
}

int main()
{
    while(cin >> N >> M && !cin.eof())
    {
	ans = 0;
	//vector<vector<bool>> adj(N, vector<bool>(N));
	//for(int i = 0 ; i < M ; ++i)
	//{
	//    int a, b;
	//    cin >> a >> b;
	//    adj[a - 1][b - 1] = true;
	//    adj[b - 1][a - 1] = true;
	//}

	vector<__int128> adj(N);
	for(int i = 0 ; i < M ; ++i)
	{
	    int a, b;
	    cin >> a >> b;
	    --a;
	    --b;
	    
	    adj[a] |= ((__int128)1 << b);
	    adj[b] |= ((__int128)1 << a);
	}
	
	__int128 startingCand = (((__int128)1 << N) - 1);

	if(N == 128)
	{
	    startingCand = -1;
	}

	solve(adj, 0, startingCand, 0);

	if(ans <= 1000)
	{
	    cout << ans << '\n';
	} else {
	    cout << "Too many maximal sets of friends.\n";
	}
    }
}
