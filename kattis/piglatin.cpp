#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    unordered_map<char, bool> isV;
    string vow = "aeiouy";
    for (auto c: vow) { isV[c] = true; }

    string line;
    while (getline(cin, line))
    {
        stringstream ss{ line };
        string word;
        while (ss >> word)
        {
            if (isV[word[0]]) { cout << word << "yay "; }
            else
            {
                auto fv = find_if(word.begin(), word.end(), [&](char c) { return isV[c]; });
                cout << string(fv, word.end()) << string(word.begin(), fv) << "ay "; 
            }
        }
        cout << '\n';
    }
}
