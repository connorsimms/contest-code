#include <bits/stdc++.h>
using namespace std;

int main()
{
    int R, C;
    cin >> R >> C;
    vector<string> grid(R);
    for(int i = 0 ; i < R; ++i)
    {
	cin >> grid[i];
    }
    
    int r = 0;
    int c = 0;

    vector<vector<bool>> seen(R, vector<bool>(C));

    if(grid[r][c] == 'T') { cout << 0 << '\n'; return 0; }

    int i = 0;

    while(true) {
	if(r < 0 || c < 0 || r >= R || c >= C) { cout << "Out\n"; break; }
	if(seen[r][c]) { cout << "Lost\n"; break; }
	if(grid[r][c] == 'T') { cout << i << '\n'; break; }

	seen[r][c] = true;

	switch(grid[r][c]) {
	    case 'N': --r; break;
	    case 'E': ++c; break;
	    case 'S': ++r; break;
	    case 'W': --c; break;
	    default: break;
	}
	
	++i;
    }
}
