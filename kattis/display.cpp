#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    unordered_map<int, string> itos;

    for (int i = 0; i <= 9; ++i) { itos[i] = string(35, ' '); }

    for (auto i : {0, 2, 3, 5, 6, 7, 8, 9})
    {
        int r = 0;
        for (int c = 0; c < 5; ++c)
        {
            itos[i][5*r + c] = (c % 4 == 0) ? '+' : '-';
        }
    }

    for (auto i : {2, 3, 4, 5, 6, 8, 9})
    {
        int r = 3;
        for (int c = 0; c < 5; ++c)
        {
            itos[i][5*r + c] = (c % 4 == 0) ? '+' : '-';
        }
    }

    for (auto i : {0, 2, 3, 5, 6, 8, 9})
    {
        int r = 6;
        for (int c = 0; c < 5; ++c)
        {
            itos[i][5*r + c] = (c % 4 == 0) ? '+' : '-';
        }
    }

    for (auto i : {0, 4, 5, 6, 8, 9})
    {
        int c = 0;
        for (int r = 0; r < 4; ++r)
        {
            itos[i][5*r + c] = (r % 3 == 0) ? '+' : '|';
        }
    }

    for (auto i : {0, 2, 6, 8})
    {
        int c = 0;
        for (int r = 4; r < 7; ++r)
        {
            itos[i][5*r + c] = (r % 3 == 0) ? '+' : '|';
        }
    }

    for (auto i : {0, 1, 2, 3, 4, 7, 8, 9})
    {
        int c = 4;
        for (int r = 0; r < 4; ++r)
        {
            itos[i][5*r + c] = (r % 3 == 0) ? '+' : '|';
        }
    }

    for (auto i : {0, 1, 3, 4, 5, 6, 7, 8, 9})
    {
        int c = 4;
        for (int r = 4; r < 7; ++r)
        {
            itos[i][5*r + c] = (r % 3 == 0) ? '+' : '|';
        }
    }

    string input; 
    while (getline(cin, input) && input != "end")
    {
        vector<int> digs(4);
        digs[0] = input[0] - '0';
        digs[1] = input[1] - '0';
        digs[2] = input[3] - '0';
        digs[3] = input[4] - '0';

        for (int r = 0 ; r < 7; ++r)
        {
            for (int i = 0; i < 4; ++i)
            {
                if (i == 2)
                {
                    if (r == 2 || r == 4) { cout << "o"; }
                    else {cout << " "; }
                    cout << "  ";
                }

                auto x = digs[i];
                cout << itos[x].substr(5 * r, 5);
                cout << (i < 3 ? "  " : "");
            }
            cout << '\n';
        }
        cout << "\n\n";
    }
    cout  << "end\n";
}
