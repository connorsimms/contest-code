#include <bits/stdc++.h>

using namespace std;

enum Direction {
    upDir,
    downDir,
    leftDir,
    rightDir
};

array<Direction, 4> allDir{ upDir, downDir, leftDir, rightDir };

const string solvedCube {"RRRRGGGGBBBBYYYY"}; 

string getMove(string from, int idx, Direction dir)
{
    char temp;
    switch(dir)
    {
    case upDir:
	temp = from[idx];
	for(int i = 0 ; i < 3 ; ++i)
	{
	    int currentRow = i;
	    int nextRow = i + 1;
	    from[idx + 4 * currentRow] = from[idx + 4 * nextRow];
	}
	from[idx + 12] = temp;
	return from;
    case downDir:
	temp = from[idx + 12];
	for(int i = 3 ; i >= 1 ; --i)
	{
	    int currentRow = i;
	    int nextRow = i - 1;
	    from[idx + 4 * currentRow] = from[idx + 4 * nextRow];
	}
	from[idx] = temp;
	return from;
    case leftDir:
	temp = from[idx * 4];
	for(int i = 0 ; i < 3 ; ++i)
	{
	    int current = i;
	    int nextCol = i + 1;
	    from[4 * idx + current] = from[4 * idx + nextCol];
	}
	from[idx * 4 + 3] = temp;
	return from;
    case rightDir:
	temp = from[idx * 4 + 3];
	for(int i = 3 ; i >= 1 ; --i)
	{
	    int current = i;
	    int nextCol = i - 1;
	    from[4 * idx + current] = from[4 * idx + nextCol];
	}
	from[idx * 4] = temp;
	return from;
    default:
	return from;
    }

    return from;
}

void solve()
{
    
}

int main()
{
    string start(16, ' ');

    for(int i = 0 ; i < 16 ; ++i)
    {
	cin >> start[i];
    }

    unordered_map<string, int> dist;
    unordered_map<string, bool> seen;

    dist[start] = 0;
    seen[start] = true;

    queue<string> q;
    q.push(start);

    while(!q.empty())
    {
	string at = q.front();
	q.pop();
	if(dist[at] == 6) { continue; }

	for(int idx = 0 ; idx < 4 ; ++idx)
	{
	    for(auto dir: allDir)
	    {
		auto nextCube = getMove(at, idx, dir);
		if(!seen[nextCube])
		{
		    dist[nextCube] = dist[at] + 1;
		    seen[nextCube] = true;
		    q.push(nextCube);
		}
	    }
	}
    }

    if(seen[solvedCube]) { 
	cout << dist[solvedCube] << '\n'; 
	return 0;
    } else {
	unordered_map<string, int> otherDist;
	unordered_map<string, bool> otherSeen;
	queue<string> oq;
	oq.push(solvedCube);
	otherDist[solvedCube] = 0;
	otherSeen[solvedCube] = true;

	int minDist = 13;

	while(!oq.empty())
	{
	    auto at = oq.front();
	    oq.pop();

	    if(otherDist[at] == 6) { continue; }

	    for(int idx = 0 ; idx < 4 ; ++idx)
	    {
		for(auto dir: allDir)
		{
		    auto next = getMove(at, idx, dir);
		    if(!otherSeen[next])
		    {
			otherDist[next] = otherDist[at] + 1;
			otherSeen[next] = true;

			if(seen[next])
			{
			    minDist = min(minDist, dist[next] + otherDist[next]);		
			}

			oq.push(next);
		    }
		}
	    }
	}

	cout << minDist << '\n';
	return 0;
    }


    return 0;
}
