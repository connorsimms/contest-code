#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n != 0)
    {
	string fav = "";
	int maxPair = 0;
	unordered_set<char> vow = {'a','e','i','o','u','y'};

	for(int i = 0 ; i < n ; ++i)
	{
	    string w; cin >> w;
	    if(i == 0) { fav = w; }
	    int np = 0;
	    for(int j = 0 ; j < w.size() - 1; ++j)
	    {
		if((vow.count(w[j]) > 0) && (vow.count(w[j + 1]) > 0) && w[j] == w[j + 1]) { ++np; }
	    }
	    if(np > maxPair) {
		maxPair = np;
		fav = w;
	    }
	}

	cout << fav << '\n';
    }
}
