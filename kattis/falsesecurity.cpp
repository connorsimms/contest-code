#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    vector<string> alph = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", 
        "...-", ".--", "-..-", "-.--", "--.."};

    unordered_map<char, string> ctom;
    unordered_map<string, char> mtoc;

    for (int i = 0; i < alph.size(); ++i) { 
        ctom['A' + i] = alph[i]; 
        mtoc[alph[i]] = 'A' + i; 
    }

    ctom['_'] = "..--";
    mtoc["..--"] = '_';
    ctom[','] = ".-.-";
    mtoc[".-.-"] = ',';
    ctom['.'] = "---.";
    mtoc["---."] = '.';
    ctom['?'] = "----";
    mtoc["----"] = '?';

    string s;
    while (cin >> s)
    {
        vector<int> num;
        string morse = "";
        for (auto c: s)
        {
            morse += ctom[c];
            num.push_back(ctom[c].size());
        }

        reverse(num.begin(), num.end());

        int f = 0;
        for (auto idx: num)
        {
            cout << mtoc[morse.substr(f, idx)];
            f += idx;
        }
        cout << '\n';
    }
}
