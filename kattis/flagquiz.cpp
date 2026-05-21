#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string junk;

    getline(cin, junk);

    int n; cin >> n;

    getline(cin, junk);

    vector<vector<string>> options;

    for (int i = 0 ; i < n ; ++i)
    {
        vector<string> option; 
        string part;

        string line;
        getline(cin, line);

        int idx = 0, next;
        while ((next = line.find(',', idx)) != -1)
        {
            option.push_back(line.substr(idx, next - idx));
            idx = next + 2;
        }
        option.push_back(line.substr(idx));

        options.push_back(option);
    } 

    vector<int> bestIdx;
    int best = 200;

    for (int i = 0 ; i < n ; ++i)
    {
        int score = 0;
        for (int j = 0 ; j < n ; ++j)
        {
            int diff = 0;
            for (int k = 0 ; k < options[i].size(); ++k)
            {
                diff += options[i][k] != options[j][k];
            }
            score = max(score, diff);
        }
        if (score == best)
        {
            bestIdx.push_back(i);
        }
        if (score < best)
        {
            bestIdx.clear();
            bestIdx.push_back(i);
            best = score;
        }
    }
    
    for (auto idx : bestIdx)
    {
        cout << options[idx][0];
        for (int i = 1 ; i < options[idx].size(); ++i)
        {
            cout << ", " << options[idx][i];
        }
        cout << '\n';
    }
}
