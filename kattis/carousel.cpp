#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; 
    while(cin >> n >> m && !(n == 0 && m == 0)) {
	long long bestN = 0, bestD = 1e9;
	for(int i = 0 ; i < n ; ++i)
	{
	    long long a, b; cin >> a >> b;
	    if(a > m) { continue; }

	    if(a * bestD == bestN * b) { 
		if(a > bestN) {
		    bestN = a;
		    bestD = b;
		}
	    }
	    if(a * bestD > bestN * b) { 
		bestN = a;
		bestD = b;
	    }
	}
	if(!(bestN == 0 && bestD == 1e9)) {
	    printf("Buy %d tickets for $%d\n", bestN, bestD);
	} else {
	    cout << "No suitable tickets offered\n";
	}
    }
}
