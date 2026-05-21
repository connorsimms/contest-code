#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<string>> board(8, vector<string>(8, "   "));
    for(int i = 0 ; i < 8 ; ++i)
    {
	for(int j = 0 ; j < 8 ; ++j)
	{
	    if(((i + j) % 2) == 0) { board[i][j] = "..."; }
	    else { board[i][j] = ":::"; }
	}
    }
    string line;

    getline(cin, line);
    line = line.substr(7);
    string piece;
    istringstream iss{line};
    while(getline(iss, piece, ','))
    {
	char type = 'P';
	if(piece.size() == 3) { 
	    type = piece[0]; 
	    int row = '8' - piece[2];
	    int col = piece[1] - 'a';
	    board[row][col][1] = type;
	} else {
	    int row = '8' - piece[1];
	    int col = piece[0] - 'a';
	    board[row][col][1] = type;
	}
    }

    getline(cin , line);
    line = line.substr(7);
    istringstream iss2{line};
    while(getline(iss2, piece, ','))
    {
	char type = 'p';
	if(piece.size() == 3) { 
	    type = piece[0]; 
	    type += ('a' - 'A');
	    int row = '8' - piece[2];
	    int col = piece[1] - 'a';
	    board[row][col][1] = type;
	} else {
	    int row = '8' - piece[1];
	    int col = piece[0] - 'a';
	    board[row][col][1] = type;
	}
    }
    string bound = "+---+---+---+---+---+---+---+---+\n";
    for(int i = 0 ; i < 8 ; ++i)
    {
	cout << bound;
	cout << "|";
	for(int j = 0 ; j < 8 ; ++j)
	{
	    cout << board[i][j] << "|";
	}
	cout << '\n';
    }
    cout << bound;
}
