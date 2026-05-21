#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, r, k; cin >> n >> r >> k;

    int steps = 0;
    steps += k; // reached office
    steps += abs(r - k); // walk to desk

    if(steps >= n) { 
	steps += r; // go home	
    } else {
	while( steps < n ) {
	    steps += 2;
	}
	steps += r; // go home
    }

    cout << steps << '\n';
}
