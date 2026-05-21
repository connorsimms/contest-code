#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int main()
{
    string s = "GFEDCBAgfedcba";
    string l = "FDBgea";

    unordered_map<char, bool> line;
    unordered_map<char, string> out;

    for (auto c: l) { line[c] = true; }

    int x; cin >> x; string junk; getline(cin, junk);
    string input; getline(cin, input);

    stringstream ss{ input };

    int totDur = 0;

    string noteDur;

    while (ss >> noteDur)
    {
        if (noteDur.size() == 1) ++totDur;
        else totDur += (noteDur[1] - '0');
    }

    for (auto n : s)
    {
        out[n] = string(totDur + x - 1, (line[n] ? '-' : ' '));
    }

    stringstream in{ input };

    int t = 0;

    while (in >> noteDur)
    {
        if (noteDur.size() == 1)
        {
            out[noteDur[0]][t++] = '*';
            t++;
        }
        else
        {
            char note = noteDur[0];
            int dur = noteDur[1] - '0';
            for (int i = 0; i < dur; ++i)
            {
                out[note][t++] = '*';
            }
            t++;
        }
    }
    for (auto n : s)
    {
        cout << n << ": " << out[n] << '\n';
    }
}
