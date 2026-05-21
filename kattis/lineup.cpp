#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool inc = true;
    bool dec = true;

    int n; cin >> n;
    string prev; cin >> prev;

    for(int i = 1 ; i < n ; ++i) {
	string curr; cin >> curr;

	if(curr > prev) { dec = false; }
	if(curr < prev) { inc = false; }

	prev = curr;
    }

    if(inc) { cout << "INCREASING\n"; }
    if(dec) { cout << "DECREASING\n"; }
    if(!inc && !dec) { cout << "NEITHER\n"; }
}
