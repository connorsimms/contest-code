#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<bool> difficulty(60);

    for(int i = 0 ; i < n ; ++i)
    {
	int x;
	cin >> x;
	difficulty[x] = true;
    }

    int count = 0;
    for(auto x: difficulty)
    {
	if(x) {
	    ++count;
	}
    }

    cout << min(count, k);

    return 0;
}
