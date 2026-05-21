#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string line;
    vector<string> dict;
    int longest = 0;
    bool first = true;
    while (getline(cin, line))
    {
        stringstream ss{ line };
        string word; ss >> word;

        if (word.empty() && !dict.empty())
        {
            if (!first)
                cout << '\n';
            else
                first = false;

            sort(dict.begin(), dict.end(), [](string A, string B) {
                reverse(A.begin(), A.end());
                reverse(B.begin(), B.end());
                return A < B;
            });

            for (auto x : dict)
            {
                for (int i = 0 ; i < longest - x.size(); ++i) { cout << " "; }
                cout << x << '\n';
            }

            dict.clear();
            longest = 0;

            continue;
        }

        dict.push_back(word);
        longest = max(longest, (int)word.size());
    }

    if (dict.empty()) return 0;

    if (!first)
        cout << '\n';
    else
        first = false;

    sort(dict.begin(), dict.end(), [](string A, string B) {
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        return A < B;
    });

    for (auto x : dict)
    {
        for (int i = 0 ; i < longest - x.size(); ++i) { cout << " "; }
        cout << x << '\n';
    }

    dict.clear();
    longest = 0;
}
