#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
#include <cmath>

using namespace std;

int main()
{
    vector<string> kb =
    {   "qwertyuiop",
        "asdfghjkl ",
        "zxcvbnm   "};

    unordered_map<char, int> r;
    unordered_map<char, int> c;

    for(int i = 0 ; i < 3; ++i)
    {
        for (int j = 0 ;j < kb[i].size(); ++j)
        {
            if (kb[i][j] == ' ') { continue; }
            r[kb[i][j]] = i;
            c[kb[i][j]] = j;
        }
    }

    int T; cin >> T;
    while (T--)
    {
        vector<pair<int, string>> lst;
        string des; cin >> des;
        int l; cin >> l;
        for (int i = 0 ; i < l ; ++i)
        {
            string word; cin >> word;
            int dist = 0;

            for (int j = 0 ; j < word.size() ; ++j)
            {
                dist += abs(r[des[j]] - r[word[j]]) + abs(c[des[j]] - c[word[j]]);
            }
            lst.emplace_back(dist, word);
        }

        sort(lst.begin(), lst.end());

        for (auto dw: lst)
        {
            cout << dw.second << " " << dw.first << '\n';
        }
    }
}
