#include <bits/stdc++.h>

using namespace std;

int ans = 15;

void solve(const vector<vector<int>>& adj, vector<int>& color, int at, int N)
{
    if(at == N)
    {
	int maxColor = 0;
	for(int i = 0 ; i < at ; ++i)
	{
	    maxColor = max(maxColor, color[i]);
	}
	ans = min(maxColor, ans);
	return;
    }

    int maxColor = 0;
    for(int i = 0 ; i < at ; ++i)
    {
	maxColor = max(maxColor, color[i]);
    }

    if(maxColor > ans) { return; }

    for(int newC = 1 ; newC <= maxColor + 1 ; ++newC)
    {
	bool valid = true;
	for(auto ne: adj[at])
	{
	    if(color[ne] == newC) { valid = false; }
	}
	if(valid)
	{
	    color[at] = newC;

	    solve(adj, color, at + 1, N);

	    color[at] = 0;
	}
    }

}

int main()
{
    int n, m;
    while((cin >> n >> m) && ((n != 0) || (m != 0)))
    {
	ans = 16;
	unordered_map<string, int> ntoi;
	vector<string> iton(n);
	vector<vector<int>> adj(n);
	int counter = 0;

	for(int i = 0 ; i < m ; ++i)
	{
	    string n1, n2;
	    cin >> n1 >> n2;
	    
	    if(!ntoi.count(n1))
	    {
		ntoi[n1] = counter;
		iton[counter] = n1;
		++counter;
	    }

	    if(!ntoi.count(n2))
	    {
		ntoi[n2] = counter;
		iton[counter] = n2;
		++counter;
	    }

	    int id1 = ntoi[n1];
	    int id2 = ntoi[n2];

	    adj[id1].push_back(id2);
	    adj[id2].push_back(id1);
	}
	
	if(m == 0)
	{
	    cout << "1\n";
	    continue;
	}

	vector<int> color(n);

	solve(adj, color, 0, n);

	cout << ans << '\n';
    }
}
