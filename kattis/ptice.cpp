#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> a = {'A','B','C'};
    vector<char> b = {'B','A','B','C'};
    vector<char> g = {'C','C','A','A','B','B'};

    int as = 0, bs = 0, gs = 0;
    int bestScore = 0;

    int n; cin >> n;
    for(int i = 0 ; i < n ; ++i)
    {
	char ans; cin >> ans;
	as += (a[(i % a.size())] == ans);
	if(as > bestScore) { bestScore = as; }
	bs += (b[(i % b.size())] == ans);
	if(bs > bestScore) { bestScore = bs; }
	gs += (g[(i % g.size())] == ans);
	if(gs > bestScore) { bestScore = gs; }
    }
    
    cout << bestScore << '\n';
    if( as == bestScore ) { cout << "Adrian\n"; }
    if( bs == bestScore ) { cout << "Bruno\n"; }
    if( gs == bestScore ) { cout << "Goran\n"; }
}
