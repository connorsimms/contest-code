#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> temp(n);
    for(int i = 0 ; i < n ; ++i) {
	cin >> temp[i]; 
    }

    int minTemp = max(temp[0], temp[2]);
    int bestDay = 0;

    for(int i = 1; i < n - 2; ++i)
    {
	int t = max(temp[i], temp[i + 2]);
	if(t < minTemp) {
	    bestDay = i;
	    minTemp = t;
	}
    }

    cout << bestDay + 1 << " " << minTemp << '\n';
}

