#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char, int> dtoi;
    dtoi['u'] = 0; dtoi['d'] = 1; dtoi['l'] = 2; dtoi['r'] = 3;

    array<int, 4> dx = {0, 0, -1, 1}; // u d l r
    array<int, 4> dy = {1, -1, 0, 0};

    int w, l;
    while(cin >> w >> l && !(w == 0 && l == 0)) 
    {
	int x = 0, y = 0;
	int realX = 0, realY = 0;
	int n; cin >> n;
	for(int i = 0 ; i < n ; ++i)
	{
	    char dir; cin >> dir;
	    int z; cin >> z;
	    
	    x += (z * dx[(dtoi[dir])]);
	    y += (z * dy[(dtoi[dir])]);

	    realX += (z * dx[(dtoi[dir])]);
	    realY += (z * dy[(dtoi[dir])]);

	    realX = max(realX, 0);
	    realX = min(realX, w - 1);
	    realY = max(realY, 0);
	    realY = min(realY, l - 1);

	    //cout << x << " " << y << " " << realX << " " << realY << '\n';
	}

	cout << "Robot thinks " << x << " " << y << '\n';
	cout << "Actually at " << realX << " "  << realY << '\n';
	cout << '\n';
    }
}
