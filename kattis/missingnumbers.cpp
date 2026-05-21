#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<bool> num(300);
    int maxN = 0;
    for(int i = 0 ; i < n; ++i)
    {
	int x; cin >> x;
	num[x] = true;
	maxN = max(maxN, x);
    }
    
    bool goodJob = true;
    for(int i = 1 ; i < maxN ; ++i)
    {
	if(!num[i]) { cout << i << '\n'; goodJob = false; }
    }

    if(goodJob) { cout << "good job\n"; }
}
