#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string line;
    string word;

    set<string> words;

    while (getline(cin, line))
    {
        stringstream ss{ line };
        while (ss >> word) words.insert(word);
    }

    set<string> comps;

    for (auto i = words.begin(); i != words.end(); ++i)
    {
        for (auto j = next(i, 1); j != words.end(); ++j)
        {
            string compound1 = *i + *j;
            string compound2 = *j + *i;

            comps.insert(compound1);
            comps.insert(compound2);
        }
    }

    for (auto x : comps)
    {
        cout << x << '\n';
    }
}
