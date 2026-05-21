#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, P, L, E, R, S, N;
    while(cin>>M>>P>>L>>E>>R>>S>>N)
    {
	for(int i = 0 ; i < N; ++i)
	{
	    int tL = L;
	    int tP = P;
	    L = M * E;
	    P = tL / R;
	    M = tP / S;
	}

	cout << M << '\n';
    }
}
