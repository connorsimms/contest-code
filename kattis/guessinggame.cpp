#include <bits/stdc++.h>
using namespace std;

int main()
{
    int g;
    int honest = true;
    vector<bool> ans(11, true);
    ans[0] = false;
    while(true)
    {
	cin >> g; if(g == 0) { break; }
	string junk; getline(cin, junk);
	string resp; getline(cin, resp);
	//cout << low << " " << g << " " << high << '\n';

	if(resp == "too high") {
	    for(int i = g ; i <= 10 ; ++i) { ans[i] = false; }
	} else if (resp == "too low") {
	    for(int i = 1 ; i <= g ; ++i) { ans[i] = false; }
	} else {
	    bool honest = ans[g];
	    cout << "Stan ";
	    cout << (honest ? "may be honest\n" : "is dishonest\n");
	    fill(ans.begin(), ans.end(), true);
	    ans[0] = false;
	}
    }
}
