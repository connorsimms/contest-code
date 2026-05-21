#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
	int n, m; cin >> n >> m;
	vector<vector<int>> prize(n);
	unordered_map<int,int> pc;
	for(int i = 0 ; i < n ; ++i)
	{
	    int k; cin >> k;
	    for(int j = 0 ; j < k ; ++j)
	    {
		int ticket; cin >> ticket;
		prize[i].push_back(ticket);
	    }
	    int cash; cin >> cash;
	    pc[i] = cash;
	}

	vector<int> tickets(m);
	for(int i = 0 ; i < m ; ++i)
	{
	    cin >> tickets[i];
	}

	int total = 0;
	for(int i = 0 ; i < n ; ++i)
	{
	    int minT = 1e9;
	    for(auto x: prize[i])
	    {
		minT = min(minT, tickets[x - 1]);
	    }
	    total += minT * pc[i];
	}

	cout << total << '\n';
    }
}
