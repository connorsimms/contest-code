#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    for(int i = 0 ; i < str.size() - 1; ++i)
    {
	if( str[i] == 's' && str[i + 1] == 's' ) {
	    cout << "hiss\n"; return 0;
	}
    }

    cout << "no hiss\n";
}
