#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, int> m;
    int n; cin >> n;
    vector<int> ds;
    for(int i = 2 ; i <= n; ++i)
    {
	int d; cin >> d;
	ds.push_back(d);
	m[d] = i;
    }
    sort(ds.begin(), ds.end());

    cout << 1 << " ";
    for(auto d: ds) {
	cout << m[d] << " ";
    }
    cout << '\n';

    return 0;
}

