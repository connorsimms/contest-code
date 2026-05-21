#include <bits/stdc++.h>

using namespace std;

using Board = string;

const string endBoard {
    "111110111100 110000100000"
};

// problem wording is incorrect (?)
//const string endBoard {
//    "000001000011 001111011111" 
//};

constexpr array<pair<int,int>,8> knightdxdy {{
    {-1,-2},
    {-1,2},
    {1,-2},
    {1,2},
    {-2,-1},
    {-2,1},
    {2,-1},
    {2,1}
}};

vector<string> getNext(string current)
{
    int brow, bcol;
    for(int i = 0 ; i < 5 ; ++i)
    {
	for(int j = 0 ; j < 5 ; ++j)
	{
	    if(current[5 * i + j] == ' ')
	    {
		brow = i;
		bcol = j;
		break;
	    }
	}
    }

    vector<string> res;

    for(auto dxdy: knightdxdy)
    {
	int r = brow + dxdy.first;
	int c = bcol + dxdy.second;
	if(r >= 0 && r < 5 && c >= 0 && c < 5)
	{
	    string newboard = current;
	    swap(newboard[brow * 5 + bcol], newboard[5 * r + c]);
	    res.push_back(newboard);
	}
    }

    return res;
}

int main()
{
    int N;
    cin >> N;
    string junk;
    getline(cin, junk);

    queue<string> q;
    unordered_map<string, int> dist;
    unordered_map<string, bool> seen;

    q.push(endBoard);
    dist[endBoard] = 0;
    seen[endBoard] = true;

    while(!q.empty())
    {
	string cur = q.front();
	q.pop();

	if(dist[cur] == 10) { continue; }

	auto nextBoards = getNext(cur);

	for(auto next: nextBoards)
	{
	    if(!seen[next])
	    {
		seen[next] = true;
		dist[next] = dist[cur] + 1;
		q.push(next);
	    }
	}

    }

    for(int t = 0 ; t < N ; ++t)
    {
	string start(25, ' ');
	for(int i = 0 ; i < 5 ; ++i)
	{
	    string line;
	    getline(cin, line);
	    for(int j = 0 ; j < 5 ; ++j)
	    {
		start[5 * i + j] = line[j];
	    }
	}

	if(seen[start])
	{
	    cout << "Solvable in " << dist[start] << " move(s).\n";
	} else {
	    cout << "Unsolvable in less than 11 move(s).\n";
	}

	continue;

	/* Meet in the middle approach if constraints were larger */
	
	queue<string> oq;
	unordered_map<string, int> odist;
	unordered_map<string, bool> oseen;

	oq.push(start);
	odist[start] = 0;
	oseen[start] = true;
	bool found = false;

	while(!oq.empty())
	{
	    string cur = oq.front();
	    oq.pop();

	    if(odist[cur] == 8) { continue; }

	    auto nextBoards = getNext(cur);

	    for(auto next: nextBoards)
	    {
		if(next == endBoard) { cout << "found endboard\n"; }
		if(seen[next])
		{
		    cout << dist[next] + odist[cur] + 1 << '\n';
		}
		if(!oseen[next])
		{
		    oseen[next] = true;
		    odist[next] = odist[cur] + 1;
		    oq.push(next);
		}
	    }
	}
    }
    return 0;
}
