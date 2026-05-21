#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, int> ptoi;
    ptoi['K'] = 0; ptoi['k'] = 0;
    ptoi['Q'] = 1; ptoi['q'] = 1;
    ptoi['R'] = 2; ptoi['r'] = 2;
    ptoi['B'] = 3; ptoi['b'] = 3;
    ptoi['N'] = 4; ptoi['n'] = 4;
    ptoi['P'] = 5; ptoi['p'] = 5;
    unordered_map<int, char> itop;
    itop[0] = 'k';
    itop[1] = 'q';
    itop[2] = 'r';
    itop[3] = 'b';
    itop[4] = 'n';
    itop[5] = 'p';

    vector<tuple<int,int,char>> white;
    vector<tuple<int,int,char>> black;

    string line;
    for(int i = 0 ; i < 8 ; ++i)
    {
	getline(cin, line);
	getline(cin, line);

	for(int j = 2 ; j < line.size() ; j += 4)
	{
	    char pos1 = 'a' + (j - 2) / 4;
	    int pos2 = 8 - i;
	    char piece = line[j];
	    int pnum = ptoi[piece];

	    if(piece >= 'A' && piece <= 'Z') {
		white.emplace_back(pnum, pos2, pos1);
	    } else if(piece >= 'a' && piece <= 'z') {
		black.emplace_back(pnum, 8 - pos2, pos1);
	    }
	}
    }
    getline(cin, line);

    sort(white.begin(), white.end());
    sort(black.begin(), black.end());

    cout << "White: ";
    for(int i = 0 ; i < white.size(); ++i)
    {
	auto piece = white[i];
	if(i != 0) { cout << ','; }
	int pnum = get<0>(piece);
	char pos1 = get<2>(piece);
	int pos2 = get<1>(piece);

	int diff = itop[pnum] - 'a';
	char p = 'A' + diff;
	if(p == 'P' ) { cout << pos1 << pos2; }
	else { cout << p << pos1 << pos2; }
    }
    cout << '\n';
    cout << "Black: ";
    for(int i = 0 ; i < black.size(); ++i)
    {
	auto piece = black[i];
	if(i != 0) { cout << ','; }
	int pnum = get<0>(piece);
	char pos1 = get<2>(piece);
	int pos2 = get<1>(piece);
	pos2 = 8 - pos2;

	int diff = itop[pnum] - 'a';
	char p = 'A' + diff;
	if(p == 'P' ) { cout << pos1 << pos2; }
	else { cout << p << pos1 << pos2; }
    }
    cout << '\n';
}
