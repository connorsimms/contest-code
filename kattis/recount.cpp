#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> votes;

    string line;

    string lead = "";
    bool tie = false;
    int best = 0;

    while (getline(cin, line) && line != "***")
    {
        ++votes[line];

        if (votes[line] == best && line != lead)
        {
            tie = true;
        }
        else if (votes[line] > best)
        {
            tie = false;
            lead = line;
            best = votes[line];
        }
    }

    if (!tie) cout << lead << '\n';
    else { cout << "Runoff!\n"; }
}
