#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    int r = 0, c = 0;

    vector<vector<char>> grid(8, vector<char>(8));
    for (int i = 0 ; i < 8 ; ++i)
    {
        for(int j = 0 ; j < 8 ; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'T' ) { r = i; c = j; }
        }
    }

    int dir = 1;
    string line, junk;
    getline(cin, junk);
    getline(cin, line);
    for(auto move: line)
    {
        //cout << r << " " << c << " " << dir << '\n';
        switch(move)
        {
            case 'F': 
            {
                r += dr[dir]; 
                c += dc[dir];

                if (r < 0 || r >= 8 || c < 0 || c >= 8) {
                    cout << "Bug!\n"; return 0;
                }

                if (grid[r][c] == 'C' || grid[r][c] == 'I') { 
                    cout << "Bug!\n"; return 0;
                }
                break;
            }
            case 'R': 
            {
                dir = (dir + 1) % 4;
                break;
            }
            case 'L': 
            {
                dir = (dir + 3) % 4;
                break;
            }
            case 'X': 
            {
                int tr = r + dr[dir]; 
                int tc = c + dc[dir]; 
                if(tr < 0 || tc < 0 || tr >= 8 || tc >= 8) {
                    cout << "Bug!\n"; return 0;
                }

                if (grid[tr][tc] == 'I') {
                    grid[tr][tc] = '.';
                } else if (grid[tr][tc] != 'D') {
                    cout << "Bug!\n"; return 0;
                }
                break;
            }
            default: break;
        }
    }

    if (grid[r][c] == 'D' ) { cout << "Diamond!\n"; }
    else { cout << "Bug!\n"; }
}
