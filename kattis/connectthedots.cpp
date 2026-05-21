#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> order;
    for(char i = '0' ; i <= '9' ; ++i) { order.push_back(i); }
    for(char i = 'a' ; i <= 'z' ; ++i) { order.push_back(i); }
    for(char i = 'A' ; i <= 'Z' ; ++i) { order.push_back(i); }

    do {
	string line;
	vector<string> grid;
	while(getline(cin, line) && line.size() != 0)
	{
	    //cout << line << '\n';
	    grid.push_back(line);
	}

	unordered_map<char, int> row;
	unordered_map<char, int> col;
	for(int i = 0 ; i < grid.size(); ++i)
	{
	    for(int j = 0 ; j < grid[0].size(); ++j)
	    {
		if(grid[i][j] != '.')
		{
		    row[grid[i][j]] = i + 1;
		    col[grid[i][j]] = j + 1;
		}
	    }
	}

	for(int i = 0 ; i < order.size() - 1; ++i)
	{
	    char curr = order[i];
	    char next = order[i + 1];
	    if(row[next] == 0) { break; }

	    int currR = row[curr]; --currR;
	    int currC = col[curr]; --currC;
	    int nextR = row[next]; --nextR;
	    int nextC = col[next]; --nextC;

	    if(currR == nextR) {
		int minCol = min(currC, nextC);
		int maxCol = max(currC, nextC);
		for(int c = minCol ; c < maxCol; ++c)
		{
		    if(grid[currR][c] == '.') { grid[currR][c] = '-'; }
		    else if(grid[currR][c] == '|') { grid[currR][c] = '+'; }
		}
	    } else {
		int minRow = min(currR, nextR);
		int maxRow = max(currR, nextR);
		for(int r = minRow ; r < maxRow; ++r)
		{
		    if(grid[r][currC] == '.') { grid[r][currC] = '|'; }
		    else if(grid[r][currC] == '-') { grid[r][currC] = '+'; }
		}
	    }
	}

	for(auto r: grid)
	{
	    for(auto c: r)
	    {
		cout << c;
	    }
	    cout << '\n';
	}
	cout << '\n';
    } while (cin);
}
