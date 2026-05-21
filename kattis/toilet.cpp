#include <iostream>
#include <string>

using namespace std;

int main()
{
    int c1 = 0, c2 = 0, c3 = 0;

    char pos1, pos2, pos3; cin >> pos1;
    pos2 = pos1; pos3 = pos1;

    string input; getline(cin, input);
    for (auto p: input)
    {
        if (p != pos1) { ++c1; }    
        if (p != pos2) { ++c2; }    
        if (p != pos3) { ++c3; }    

        pos1 = pos2 = pos3 = p;
          
        c1 += (pos1 != 'U');
        c2 += (pos2 != 'D');

        pos1 = 'U';
        pos2 = 'D';
    }

    cout << c1 << '\n' << c2 << '\n' << c3 << '\n';
}
