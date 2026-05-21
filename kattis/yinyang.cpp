#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin >> input;

    int cw = 0; int cb = 0;

    for(int i = 0 ; i < input.size() ; ++i)
    {
	if(input[i] == 'W') { ++cw; }
	if(input[i] == 'B') { ++cb; }
    }

    cout << (cw == cb) << '\n';
}
