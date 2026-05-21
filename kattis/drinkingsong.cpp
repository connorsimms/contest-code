#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n; string str; cin >> str;

    for(int i = n ; i >= 3 ; --i)
    {
	cout 	<< i << " bottles of " << str << " on the wall, " << i 
		<< " bottles of " << str << ".\n" << "Take one down, pass it around, " 
		<< i - 1 << " bottles of " << str << " on the wall.\n\n";
    }
    if(n >= 2) {
	cout 	<< 2 << " bottles of " << str << " on the wall, " << 2 
		<< " bottles of " << str << ".\n" << "Take one down, pass it around, " 
		<< 1 << " bottle of " << str << " on the wall.\n\n";
    }
	cout 	<< 1 << " bottle of " << str << " on the wall, " << 1 
		<< " bottle of " << str << ".\n" << "Take it down, pass it around, " 
		<< "no more bottles of " << str << ".\n";
}
