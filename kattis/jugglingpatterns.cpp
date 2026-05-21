#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    string pattern;
    while (getline(cin, pattern))
    {
        cout << pattern << ": ";

        unordered_set<int> landings;

        int total = 0;
        for (int i = 0 ; i < pattern.size(); ++i)
        {
            total += pattern[i] - '0';
        }

        if (total % pattern.size() != 0)
        {
            cout << "invalid # of balls\n";
            continue;
        }

        bool valid = true;

        for (int i = 0 ; i < pattern.size(); ++i)
        {
            int beat = pattern[i] - '0' + i;
            beat %= pattern.size(); 

            if (landings.count(beat))
            {
                valid = false;
            }

            landings.insert(beat);
        }

        if (valid) cout << "valid with " << total / pattern.size() << " balls\n";
        else cout << "invalid pattern\n";
    }
}
