#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    vector<string> kb = {
        "`1234567890-=",
        "QWERTYUIOP[]\\",
        "ASDFGHJKL;'",
        "ZXCVBNM,./"
    };

    unordered_map<char, char> conv;
    conv[' '] = ' ';

    for(auto row: kb)
    {
        for(int i = 1 ; i < row.size() ; ++i)
        {
            conv[row[i]] = row[i-1]; 
        }
    }

    string line;
    while(getline(cin, line) && !line.empty()) {
        for(auto c: line)
        {
            cout << conv[c];
        }
        cout << '\n';
    }
}
