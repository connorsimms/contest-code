#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;

    unordered_set<int> p1;
    unordered_set<int> p2;

    for(int i = 0 ; i < k ; ++i)
    {
	int x;
	cin >> x;

	p1.insert(x);
    }
    
    cin >> k;

    for(int i = 0 ; i < k ; ++i)
    {
	int x;
	cin >> x;
	
	p2.insert(x);
    }

    int count = 0;

    bool oneLike = true;
    bool twoLike = true;

    for(int i = 0 ; i < 1000000; ++i)
    {
	if(p1.count(i) == 0 && p2.count(i) == 0) { continue; }

	if((p1.count(i) == 0 && !oneLike) || (p2.count(i) == 0 && !twoLike))
	{
	    continue;
	}

	if(p1.count(i) != 0) { oneLike = true; }
	else { oneLike = false; }
	
	if(p2.count(i) != 0) { twoLike = true; }
	else { twoLike = false; }

	++count;
    }
    
    cout << count;
}
