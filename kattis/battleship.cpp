#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
int main()
{
    int t; cin >> t;
    while(t-- > 0) {
        int w, h, n; cin >> w >> h >> n;
        vector<vector<char>> p1(w, vector<char>(h));
        vector<vector<char>> p2(w, vector<char>(h));

        int ships1 = 0, ships2 = 0;

        for(int i = h - 1 ; i >= 0 ; --i)
        {
            for(int j = 0 ; j < w ; ++j)
            {
                cin >> p1[j][i];
                if (p1[j][i] == '#' ) { ++ships1; }
            }
        }

        for(int i = h - 1 ; i >= 0 ; --i)
        {
            for(int j = 0 ; j < w ; ++j)
            {
                cin >> p2[j][i];
                if (p2[j][i] == '#' ) { ++ships2; }
            }
        }

        int moves1 = 0;
        int moves2 = 0;
        bool turn1 = true;
        bool turn2 = false;
        bool ended = false;

        for(int i = 0 ; i < n ; ++i)
        {
            int x, y; cin >> x >> y;

            if (ended) { continue; }
            
            if (turn1) {
                ++moves1;
                if ( p2[x][y] == '#' ) {
                    p2[x][y] = '_';
                    --ships2;
                    turn1 = ships2 > 0;
                    turn2 = (ships2 == 0) && (moves2 < moves1);
                } else {
                    turn1 = false;
                    turn2 = (ships2 > 0) || (moves2 < moves1);
                }
            } else if (turn2) {
                ++moves2;
                if ( p1[x][y] == '#' ) {
                    p1[x][y] = '_';
                    --ships1;
                    turn2 = ships1 > 0;
                    turn1 = (ships1 == 0) && (moves1 < moves2);
                } else {
                    turn2 = false;
                    turn1 = (ships1 > 0) || (moves1 < moves2);
                }
            }

            if(moves1 == moves2 && (ships1 == 0 || ships2 == 0)) { ended = true; }
        }

        bool draw = false;
        if(ships1 == 0 && ships2 == 0) {
            draw = true;
        }

        if(ships1 != 0 && ships2 != 0) {
            draw = true;
        }

        if (draw) {
            cout << "draw\n";
        } else {
            cout << (ships1 > 0 ? "player one wins\n" : "player two wins\n");
        }
    }
}
