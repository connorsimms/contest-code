#include <bits/stdc++.h>

using namespace std;

array<pair<int,int>,8> dxdy {{
    {-1,-1},
    {-1, 1},
    { 1,-1},
    { 1, 1},
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1}
}};

int score(int sizeofx)
{
    switch(sizeofx)
    {
	case 1: return 0;
	case 2: return 0;
	case 3: return 1;
	case 4: return 1;
	case 5: return 2;
	case 6: return 3;
	case 7: return 5;
	case 8: return 11;
	default: return 0;
    }
}

unordered_set<string> wordsFound;

void solve(const unordered_set<string>& dict, const unordered_set<string>& subDict, 
	   const string& board, string& curr, int row, int col, int used_mask)
{
    if(!subDict.count(curr))
    {
	return;
    }

    if(dict.count(curr))
    {
	wordsFound.insert(curr);	
    }

    if(curr.length() >= 8)
    {
	return;
    }

    for(auto dir: dxdy)
    {
	int nr = row + dir.first;
	int nc = col + dir.second;

	if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4)
	{
	    continue;
	}

	int idx = nr * 4 + nc;

	if(((used_mask & (1 << idx)) == 0))
	{
	    int new_mask = (used_mask | (1 << idx));
	    curr.push_back(board[idx]);
	    solve(dict, subDict, board, curr, nr, nc, new_mask);
	    curr.pop_back();
	}
    }
}

int main()
{
    int w;
    cin >> w;

    unordered_set<string> dict;
    unordered_set<string> subDict;

    for(int i = 0 ; i < w ; ++i)
    {
	string word;
	cin >> word;
	dict.insert(word);

	for(int s = 0 ; s <= word.length() ; ++s)
	{
	    subDict.insert(word.substr(0, s));
	}
    }

    int b;
    cin >> b;

    for(int t = 0 ; t < b ; ++t)
    {
	string board(16, ' ');

	for(int i = 0 ; i < 16 ; ++i)
	{
	    cin >> board[i];
	}

	wordsFound.clear();

	for(int i = 0 ; i < 4 ; ++i)
	{
	    for(int j = 0 ; j < 4 ; ++j)
	    {
		string start{};
		int idx = 4 * i + j;
		start.push_back(board[idx]);
		int mask = (1 << idx);
		
		if(subDict.count(start))
		{
		    solve(dict, subDict, board, start, i, j, mask);
		}
	    }
	}

	int maxScore = 0;
	string longest{""};
	for(auto word: wordsFound)
	{
	    maxScore += score(static_cast<int>(word.length()));
	    if(word.length() > longest.length())
	    {
		longest = word;
	    } else if(word.length() == longest.length())
	    {
		longest = (word < longest) ? word : longest;
	    }
	}
	cout << maxScore << " " << longest << " " << wordsFound.size() << '\n';
    }
}
