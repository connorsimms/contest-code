#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> pen(26);
    vector<bool> solve(26);
    int time;
    while(cin >> time && time != -1) {
	char p; cin >> p;
	string s; cin >> s;

	int px = p - 'A';
	bool solved = (s == "right");

	pen[px] += (solved ? time : 20);
	solve[px] = solved;
    }

    int numSolve = 0;
    int totalPen = 0;

    for(int i = 0 ; i < 26 ; ++i) {
	if(solve[i]) {
	    ++numSolve;
	    totalPen += pen[i];
	}
    }
    
    cout << numSolve << " " << totalPen << '\n';
}
