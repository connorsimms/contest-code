#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long minCost = 1e9;

    int N, B, H, W; cin >> N >> B >> H >> W;

    for(int i = 0 ; i < H ; ++i)
    {
	long long p; cin >> p;
	for(int j = 0 ; j < W ; ++j)
	{
	    int x; cin >> x;
	    if(x >= N) { minCost = min(minCost, p); }
	}
    }

    if(minCost * N <= B) { cout << minCost * N << '\n'; }
    else { cout << "stay home\n"; }
}
