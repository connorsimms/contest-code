#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    string line; getline(cin, line);
    string vow = "aeiou";
    unordered_map<char, bool> isV;
    for (auto c: vow) { isV[c] = true; }

    if (line.size() <= 2) { cout << line << '\n'; return 0; }

    for (int i{1}; i < line.size() - 1; ++i)
    {
        if ((line[i] == 'p') && (line[i - 1] == line[i + 1]) && (isV[line[i - 1]])) {
            line.erase(i, 2);
        }
    }

    cout << line << '\n';
}
