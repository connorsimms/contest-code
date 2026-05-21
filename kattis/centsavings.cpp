#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9;
//
// idx of item, divider left
// use range sum query for subtotals
//
vector<vector<long long>> memo(2001, vector<long long>(21, -1)); 

long long solve(const vector<int>& rsq, int idx, int d_left) {
    if(idx >= rsq.size()) { return 0; }

    if(memo[idx][d_left] != -1) { return memo[idx][d_left]; }

    if(d_left == 0) { // return rounded subtotal from idx to end
	int x = rsq[rsq.size() - 1] - rsq[idx - 1];
	memo[idx][0] = (x + 5) / 10 * 10;
	return (x + 5) / 10 * 10;
    }

    // find position of next divider that minimizes next subtotal
    int min = INF;
    for(int i = 0 ; idx + i < rsq.size() ; ++i)
    {
	int x = rsq[idx + i] - rsq[idx - 1];
	int val = (x + 5) / 10 * 10 + solve(rsq, idx + i + 1, d_left - 1);

	if(val < min) { min = val; } 
    }

    memo[idx][d_left] = min;

    return min;
}

int main()
{
    int n, d;
    cin >> n >> d;

    vector<int> rsq(n + 1);

    rsq[0] = 0;

    for(int i = 1 ; i < n + 1 ; ++i)
    {
	cin >> rsq[i];

	if(i != 0) { rsq[i] += rsq[i - 1]; }
    }

    cout << solve(rsq, 1, d);
}
