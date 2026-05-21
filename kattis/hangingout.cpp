#include <bits/stdc++.h>
using namespace std;

int main()
{
    int L, N; cin >> L >> N;

    int count = 0;
    int rej = 0;

    for(int i = 0 ; i < N ; ++i)
    {
	string ev; cin >> ev;
	int n; cin >> n;

	if( ev == "enter" ) {
	    if(n + count > L) {
		++rej;
	    } else {
		count += n;
	    }
	} else {
	    count -= n;
	}
    }
    
    cout << rej << '\n';
}
