#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while(T--) {
	int ng, nm; cin >> ng >> nm;
	int maxG = 0;
	for(int i = 0 ; i < ng ; ++i)
	{
	    int x; cin >> x;
	    maxG = max(x, maxG);
	}

	int maxM = 0;
	for(int i = 0 ; i < nm; ++i)
	{
	    int x; cin >> x;
	    maxM = max(x, maxM);
	}

	cout << ((maxG >= maxM) ? "Godzilla" : "MechaGodzilla");
	cout << '\n';
    }
}
