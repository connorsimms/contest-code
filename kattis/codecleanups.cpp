#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> days;
    for(int i = 0 ; i < n ; ++i)
    {
	int d; cin >> d;
	days.push_back(d);
    }

    int ans = 0;
    int idx = 0;
    int dirtiness = 0;
    int numPushes = 0;
    for(int i = days[0] ; i <= 365 ; ++i)
    {
	if(i == days[idx]) {
	    ++idx;
	    numPushes++;
	}
	if(dirtiness + numPushes >= 20) { ++ans; dirtiness = 0; numPushes = 0; }
	else { dirtiness += numPushes; }
    }
    if(dirtiness != 0) { ++ans; }
    cout << ans << '\n';
    return 0;
}
