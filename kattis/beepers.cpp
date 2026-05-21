#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for(int tc = 0 ; tc < N ; ++tc)
    {
	int wx, wy;
	cin >> wx >> wy;

	int kx, ky;
	cin >> kx >> ky;

	int n;
	cin >> n;

	vector<pair<int,int>> beeper(n);

	for(int i = 0 ; i < n ; ++i)
	{
	    cin >> beeper[i].first;
	    cin >> beeper[i].second;
	}

	vector<int> beeperIdx(n);
	iota(beeperIdx.begin(), beeperIdx.end(), 0);

	int minCost = 1e9 + 1;

	do {
	    int cost = 0;
	    pair<int,int> currPos = make_pair(kx, ky);

	    for(int i = 0 ; i < beeperIdx.size(); ++i)
	    {
		int dx = (currPos.first - beeper[beeperIdx[i]].first); 
		int dy = (currPos.second - beeper[beeperIdx[i]].second); 
		cost += abs(dx) + abs(dy);

		currPos = beeper[beeperIdx[i]];
	    }

	    int dx = currPos.first - kx;
	    int dy = currPos.second - ky;

	    cost += abs(dx) + abs(dy);

	    minCost = min(minCost, cost);
	} while(next_permutation(beeperIdx.begin(), beeperIdx.end()));

	cout << minCost << '\n';
    }
}
