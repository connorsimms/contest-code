#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ar, ac, tr, tc;

    while(cin >> ar >> ac >> tr >> tc)
    {
	int paddedRows = (ar / tr + (ar % tr != 0) + 2) * tr;
	int paddedCols = (ac / tc + (ac % tc != 0) + 2) * tc;

	vector<vector<char>> paddedGrid(paddedRows, vector<char>(paddedCols, '.'));

	for(int i = 0 ; i < ar ; ++i)
	{
	    for(int j = 0 ; j < ac ; ++j)
	    {
		cin >> paddedGrid[tr + i][tc + j];
	    }
	}

	vector<vector<int>> sumGrid(paddedRows, vector<int>(paddedCols, 0));

	for(int i = tr ; i < paddedRows ; ++i)
	{
	    for(int j = tc ; j < paddedCols; ++j)
	    {
		sumGrid[i][j] = sumGrid[i - 1][j] + sumGrid[i][j - 1] - sumGrid[i-1][j-1] + (paddedGrid[i][j] == 'X');
	    }
	}

	int minTileCount = 1000000000;

	for(int startRow = 0 ; startRow < tr ; ++startRow)
	{
	    for(int startCol = 0 ; startCol < tc ; ++startCol)
	    {
		int tileCount = 0;
		for(int tileRow = 0 ; tileRow < ar + tr ; tileRow += tr)
		{
		    for(int tileCol = 0 ; tileCol < ac + tc; tileCol += tc)
		    {
			int tlRow = startRow + tileRow;
			int tlCol = startCol + tileCol;
			int brRow = startRow + tileRow + tr - 1;
			int brCol = startCol + tileCol + tc - 1;

			int total = sumGrid[brRow][brCol];
			int topSum = (tlRow > 0) ? sumGrid[tlRow - 1][brCol] : 0;
			int leftSum = (tlCol > 0) ? sumGrid[brRow][tlCol - 1] : 0;
			int topLeftSum = (tlRow > 0 && tlCol > 0) ? sumGrid[tlRow - 1][tlCol - 1] : 0;
			if(total - topSum - leftSum + topLeftSum) { ++tileCount; }
		    }
		}
		if(minTileCount > tileCount)
		{
		    minTileCount = tileCount;
		}
	    }
	}
	cout << minTileCount << '\n';
    }
    return 0;
}
