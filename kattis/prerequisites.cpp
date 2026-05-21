#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, m;
    while(cin >> k && k != 0)
    {
	cin >> m;

	set<string> courses;

	for(int i = 0 ; i < k ; ++i)
	{
	    string c; cin >> c;
	    courses.insert(c);
	}

	vector<int> catHave(m);
	vector<int> catNeed(m);

	for(int i = 0 ; i < m ; ++i)
	{
	    int cr;
	    cin >> cr;
	    cin >> catNeed[i];
	    for(int j = 0 ; j < cr; ++j)
	    {
		string c;
		cin >> c;
		if(courses.count(c)) { catHave[i]++; }
	    }
	}

	bool works = true;
	for(int i = 0 ; i < m ; ++i)
	{
	    if( catHave[i] < catNeed[i] ) { works = false; }
	}

	cout << (works ? "yes\n" : "no\n");
    }
}
