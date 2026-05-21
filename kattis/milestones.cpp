#include <bits/stdc++.h>

using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;

    vector<long long> times(M);

    for(int i = 0 ; i < M ; ++i)
    {
	cin >> times[i];	
    }

    vector<long long> stones(N);

    for(int i = 0 ; i < N ; ++i)
    {
	cin >> stones[i];
    }

    set<pair<long long,long long>> speeds;

    for(int i = 0 ; i <= stones.size() - M ; ++i)
    {
	bool valid = true;
	long long dx = stones[i + 1] - stones[i];
	long long dt = times[1] - times[0];
	for(int j = 2 ; j < M ; ++j)
	{
	    long long otherdx = stones[i + j] - stones[i + j - 1];
	    long long otherdt = times[j] - times[j - 1];
	    if(dx * otherdt != otherdx * dt)
	    {
		valid = false;
		break;
	    }
	}
	if(valid)
	{
	    speeds.insert({dx,dt});
	}
    }

    cout << speeds.size() << '\n';
    for(auto x: speeds)
    {
	cout << x.first << " ";
    }
    if(!speeds.empty()) {cout << '\n';}
}
