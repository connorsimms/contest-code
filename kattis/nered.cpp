#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> getFactorization(int x)
{
    vector<pair<int,int>> res;
    for(int i = 1 ; i * i <= x ; ++i)
    {
	if(x % i == 0)
	{
	    res.emplace_back(i, x / i);
	    res.emplace_back(x / i, i);
	}
    }
    return res;
}

int main()
{
    int N, M;

    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(N));

    for(int i = 0 ; i < M ; ++i)
    {
	int r, c;
	cin >> r >> c;
	--r;
	--c;
	++grid[r][c];
    }

    auto rec_dim = getFactorization(M);

    int bestAns = 1000000;

    for(int row = 0 ; row < N ; ++row)
    {
	for(int col = 0 ; col < N ; ++col)
	{
	    for(auto rec: rec_dim)
	    {
		int orow = row + rec.first;
		int ocol = col + rec.second;
		if(orow <= N && ocol <= N)
		{
		    int num_empty = 0;
		    for(int cr = row ; cr < orow ; ++cr)
		    {
			for(int cc = col ; cc < ocol ; ++cc)
			{
			    if(!grid[cr][cc])
			    {
				++num_empty;
			    }
			}
		    }
		    bestAns = min(bestAns, num_empty);
		}
	    }
	}
    }

    cout << bestAns << '\n';
}
