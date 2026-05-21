#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> tblr(4);
    for(int i = 0 ; i < n ; ++i)
    {
	string str; cin >> str;

	for(int j = 0 ; j < 4; ++j)
	{
	    if(str[j] == '0') { tblr[j]++; }
	}
    }

    int tb = tblr[0] + tblr[1];
    int lr = tblr[2] + tblr[3];

    int ans = min(tb/2, lr/2);
    cout << ans << " " << tb - 2 * ans << " " << lr - 2 * ans << '\n';
}
