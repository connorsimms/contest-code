#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
	int n; cin >> n;
	vector<int> votes(n);
	int maxV = 0;
	int winner = 0;
	int total = 0;
	for(int i = 0; i < n ; ++i)
	{
	    cin >> votes[i];
	    total += votes[i];
	    if(votes[i] > maxV) { maxV = votes[i]; winner = i; }
	}
	bool noWin = false;
	for(int i = 0 ; i < n ; ++i) {
	    if(votes[i] == maxV && i != winner) {
		cout << "no winner\n";
		noWin = true;
		break;
	    }
	}
	if(!noWin) {
	    cout << ((maxV * 2 > total) ? "majority " : "minority ");
	    cout << "winner " << winner + 1 << '\n';
	}
    }
}
