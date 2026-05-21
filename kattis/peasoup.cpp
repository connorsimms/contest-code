#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;

    while(t--) {
	int n; cin >> n; string name, junk; getline(cin, junk); getline(cin, name);
	bool pan = false; bool pea = false;
	for(int i = 0 ; i < n; ++i)
	{
	    string item; getline(cin, item);
	    if(item == "pea soup") { pea = true; }
	    if(item == "pancakes") { pan = true; }
	}
	if(pea && pan) { cout << name << '\n'; return 0; }
    }
    cout << "Anywhere is fine I guess\n";
}
