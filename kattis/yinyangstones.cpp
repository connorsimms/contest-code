#include <bits/stdc++.h>
using namespace std;

int main()
{
    int b = 0, w = 0;
    string str; cin >> str;

    for(char c: str)
    {
	if (c == 'W') { ++w; }
	if (c == 'B') { ++b; }
    }

    cout << (w == b) << '\n';
}
