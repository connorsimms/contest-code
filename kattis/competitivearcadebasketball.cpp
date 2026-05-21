#include <iostream>
#include  <sstream>
#include <unordered_map>
using namespace std;

int main()
{
    int n, p, m; cin >> n >> p >> m;

    string line;
    getline(cin, line);

    for (int i = 0; i < n; ++i)
    {
        getline(cin, line);
    }

    unordered_map<string, int> pts;
    bool winner = false;

    string name; int pt;

    for (int i = 0 ; i < m; ++i)
    {
        getline(cin, line);
        int idx = -1;
        for (int i = line.size() - 1; i >= 0; --i)
        {
            if (line[i] == ' ') 
             {
                idx = i;
                break;
             }
        }

        string name = line.substr(0, idx);
        string point = line.substr(idx, line.size() - idx);
        stringstream ss{ point };
        int pt; ss >> pt;

        //cout << name << ':'  << pt << '\n';

        if (pts[name] < p && pts[name] + pt >= p)
        {
            cout << name << " wins!\n";
            winner = true;
        }

        pts[name] += pt;
    }

    if (!winner)
    {
        cout << "No winner!\n";
    }
}
