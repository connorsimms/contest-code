#include <bits/stdc++.h>
using namespace std;

int main()
{
    long double spent = 0.0;
    long long hold = 0;
    long double avg;

    while(true) 
    {
	string event; cin >> event;
	if(event == "buy") {
	    int x, y; cin >> x >> y;
	    spent += x * y;
	    hold += x;
	    avg = spent / hold;
	}
	if(event == "sell") {
	    int x, y; cin >> x >> y;
	    hold -= x;
	    spent -= x * avg;
	}
	if(event == "split") {
	    int x; cin >> x;
	    hold *= x;
	    avg /= x;
	}
	if(event == "merge") {
	    int x; cin >> x;
	    spent -= (hold % x) * avg;
	    hold /= x;
	    avg *= x;
	}
	if(event == "die") {
	    int y; cin >> y;
	    if(avg > y) { cout << hold * y << '\n'; }
	    else { 
		cout << fixed << setprecision(3) 
		<< hold * y - ((hold * (y - avg)) * 0.3) << '\n'; 
	    }
	    break;
	}
    }
}
