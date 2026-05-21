#include <bits/stdc++.h>

using namespace std;

int solve(const vector<vector<pair<int,int>>>& bags, const vector<vector<int>>& candyBags, const vector<vector<int>>& antiCandyBags, int setting)
{ // 1 is maximizing, 0 is minimizing (anti)
    int res = 0;

    for(int i = 0 ; i < bags.size() ; ++i)
    {
	auto bag = bags[i];
	int score = 0;
	for(auto candy: bag)
	{
	    int t = candy.first;
	    int n = candy.second;

	    if(t < 0) { n *= -1; }

	    int bit = abs(t) - 1;
	    int state = setting & (1 << bit);

	    if(state != 0) // maximize
	    {
		score += n;
	    } else { // minimize
		score -= n;
	    }
	}
	if(score > 0)
	{
	    res += score;
	}
    }

    return res;
}

int main()
{
    
    int N;
    cin >> N;

    vector<vector<pair<int,int>>> bags(N);

    vector<vector<int>> candyBags(11);
    vector<vector<int>> antiCandyBags(11);
    
    for(int i = 0 ; i < N ; ++i)
    {
	int k;
	cin >> k;
	for(int j = 0 ; j < k ; ++j)
	{
	    int s, n;
	    cin >> s >> n;

	    bags[i].emplace_back(s,n);

	    if(s < 0) { 
		s *= -1;
		antiCandyBags[s].push_back(i);
	    } else { 
		candyBags[s].push_back(i);
	    }
	}
    }

    int ans = 0;

    for(int subset = 0 ; subset < (1 << 10) ; ++subset)
    {
	int res = solve(bags, candyBags, antiCandyBags, subset);
	ans = max(ans, res);
    }
    
    cout << ans << '\n';
}
