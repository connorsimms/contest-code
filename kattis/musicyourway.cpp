#include <iostream>
#include <numeric>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string attrline; getline(cin, attrline); 
    stringstream ss{ attrline };
    
    unordered_map<string, int> attrIdx;

    int idx = 0;

    string attr;
    while (ss >> attr)
    {
        attrIdx[attr] = idx++;
    }

    string line;
    int n; cin >> n; getline(cin, line);
    vector<string> songs(n);

    vector<vector<string>> data(n);

    for (int i = 0 ; i < n ; ++i)
    {
        getline(cin, songs[i]); 
        istringstream input{ songs[i] };

        vector<string> songInfo(idx);

        for (int j = 0 ; j < idx ; ++j)
        {
            getline(input, songInfo[j], ' ');
        }

        data[i] = songInfo;
    }

    int m; cin >> m;
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);

    vector<string> commands(m);
    for (int i = 0 ; i < m; ++i)
    {
        cin >> commands[i];
    }

    bool first = true;
    for (auto cmd: commands)
    {
        if (!first) cout << '\n';
        else first = false;

        stable_sort(indices.begin(), indices.end(), [&](int A, int B) {
            return data[A][attrIdx[cmd]] < data[B][attrIdx[cmd]];
        });

        cout << attrline << '\n';
        for (auto i: indices)
        {
            cout << songs[i] << '\n';
        }
    }

}
