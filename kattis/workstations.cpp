#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    priority_queue<int, vector<int>, greater<int>> minArrival;
    priority_queue<int, vector<int>, greater<int>> minEnd;

    for(int i = 0 ; i < n ; ++i)
    {
	int a, s;
	cin >> a >> s;
	
	minArrival.emplace(a);
	minEnd.emplace(a + s);
    }

    int count = 0;

    for(; !minEnd.empty() && !minArrival.empty(); )
    {
	int s = minArrival.top();
	int e = minEnd.top();

	if(s >= e && s <= e + m) { 
	    ++count; 
	    minArrival.pop();
	    minEnd.pop();
	}

	if(s > e + m) { minEnd.pop(); }
	if(s < e) { minArrival.pop(); }
    }

    cout << count << '\n';
}

