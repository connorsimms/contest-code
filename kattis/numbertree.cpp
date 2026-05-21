#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string line; getline(cin, line);
    stringstream ss{ line };

    int n;
    ss >> n;

    int total = (1 << (n + 1));

    string moves; ss >> moves;

    int curr = 0;

    for (auto x : moves)
    {
        if (x == 'L')
        {
            curr = curr * 2 + 1;
        }
        if (x == 'R')
        {
            curr = curr * 2 + 2;
        }
    }
    
    cout << total - 1 - curr << '\n';
}
