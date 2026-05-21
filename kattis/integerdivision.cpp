#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int d; cin >> d;

    map<int, int> div;
    map<int,int> count;
    unordered_set<int> elems;

    for(int i = 0 ; i < n ; ++i)
    {
	int x; cin >> x;
	elems.insert(x);
	++count[x];
	++div[(x / d)];
    }

    long long ans = 0;

    for(auto x: div)
    {
	long long num = x.second;
	long long pair = num * (num - 1) / 2;

	ans+= (pair);
    }

    cout << ans << '\n';
}
