#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    string p1, p2; cin >> p1 >> p2;
    int N; cin >> N;
    string jnk; getline(cin, jnk);
    while (N--)
    {
        string game;
        getline(cin, game);
        stringstream ss{game};
        bool valid = true;
        int sets = 0;
        int sets1 = 0;
        int sets2 = 0;

        string set;
        while (ss >> set)
        {
            ++sets;
            if (sets1 == 2 || sets2 == 2) { valid = false; }

            auto div = set.find(':');
            string g1 = set.substr(0, div);
            string g2 = set.substr(div + 1);
            int game1 = stoi(g1);
            int game2 = stoi(g2);

            if (game1 < game2 && p1 == "federer") { valid = false; }
            if (game2 < game1 && p2 == "federer") { valid = false; }

            if (max(game1, game2) < 6) { valid = false; }
            if (max(game1, game2) > 7 && sets <= 2) { valid = false; }

            if (max(game1, game2) == 7 && min(game1, game2) == 6) {
                if (sets > 2) { valid = false; }
            } else if (max(game1, game2) - min(game1, game2) < 2) {
                valid = false; 
            } else if (max(game1, game2) - min(game1, game2) > 2) {
                if (max(game1, game2) != 6) { valid = false; }
            }

            if (game1 < game2) { ++sets2; }
            if (game2 < game1) { ++sets1; }
        }

        if (sets > 3) { valid = false; }
        if (sets < 2) { valid = false; }
        if (max(sets1, sets2) != 2) { valid = false; }
        if (min(sets1, sets2) >= 2) { valid = false; }

        cout << (valid ? "da\n" : "ne\n");
    }
}
