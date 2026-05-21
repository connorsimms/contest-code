#include <bits/stdc++.h>

using namespace std;

int N;
int ans = 0;

void solve(vector<vector<char>>& grid, int nQueen, int row, int col, int d1, int d2)
{
    if(nQueen == N)
    {
	++ans;
	return;
    }

    for(int i = 0 ; i < N ; ++i)
    {
	bool notHole = (grid[nQueen][i] != 'h');
	bool openRow = ((row & (1 << nQueen)) == 0);
	bool openCol = ((col & (1 << i)) == 0);
	int bitd1 = nQueen + i;
	bool openD1 = ((d1 & (1 << bitd1)) == 0);	
	int bitd2 = nQueen - i + N;
	bool openD2 = ((d2 & (1 << bitd2)) == 0);
	
	if(notHole && openRow && openCol && openD1 && openD2)
	{
	    grid[nQueen][i] = 'q';

	    int newRow = (row | (1 << nQueen));
	    int newCol = (col | (1 << i));
	    int newD1 = (d1 | (1 << (nQueen + i)));	
	    int newD2 = (d2 | (1 << (nQueen - i + N)));

	    solve(grid, nQueen + 1, newRow, newCol, newD1, newD2);
	    grid[nQueen][i] = 0;
	}
    }
}

int main()
{
    int M;
    while(cin >> N >> M)
    {
	if(N == 0 && M == 0) { break;}
	ans = 0;
	vector<vector<char>> grid(N, vector<char>(N, 0));

	for(int i = 0 ; i < M ; ++i)
	{
	    int a, b;
	    cin >> a >> b;
	    grid[a][b] = 'h';
	}

	solve(grid, 0, 0, 0, 0, 0);
	cout << ans << '\n';
    }
}
