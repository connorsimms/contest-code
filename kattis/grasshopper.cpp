#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9;

int R, C;

vector<pair<int,int>> getNext(int r, int c)
{
    vector<pair<int,int>> res;
    if(r + 1 < R && c + 2 < C)	{ res.emplace_back(r + 1, c + 2); }
    if(r + 1 < R && c - 2 >= 0)	{ res.emplace_back(r + 1, c - 2); }
    if(r + 2 < R && c + 1 < C)	{ res.emplace_back(r + 2, c + 1); }
    if(r + 2 < R && c - 1 >= 0)	{ res.emplace_back(r + 2, c - 1); }
    if(r - 1 >= 0 && c + 2 < C)	{ res.emplace_back(r - 1, c + 2); }
    if(r - 1 >= 0 && c - 2 >= 0){ res.emplace_back(r - 1, c - 2); }
    if(r - 2 >= 0 && c + 1 < C)	{ res.emplace_back(r - 2, c + 1); }
    if(r - 2 >= 0 && c - 1 >= 0){ res.emplace_back(r - 2, c - 1); }

    return res;
}

int main()
{
    int Gr, Gc, Lr, Lc;
    while(cin >> R >> C >> Gr >> Gc >> Lr >> Lc)
    {
	--Gr; --Gc; --Lr; --Lc;

	vector<vector<bool>> seen(R, vector<bool>(C));

	vector<vector<int>> dist(R, vector<int>(C, INF));

	seen[Gr][Gc] = true;
	dist[Gr][Gc] = 0;

	queue<pair<int,int>> q;
	q.emplace(Gr, Gc);

	bool found = false;
	
	while(!q.empty())
	{
	    if(found) { break; }
	    auto curr = q.front();
	    q.pop();
	    for(auto next: getNext(curr.first, curr.second))
	    {
		if(!seen[next.first][next.second])
		{
		    seen[next.first][next.second] = true;
		    dist[next.first][next.second] = dist[curr.first][curr.second] + 1;
		    if(next.first == Lr && next.second == Lc)
		    {
			found = true;
			break;
		    }
		    q.push(next);
		}
	    }
	}

	if(dist[Lr][Lc] == INF)
	{
	    cout << "impossible\n";
	} else {
	    cout << dist[Lr][Lc] << '\n';
	}
    }
}
