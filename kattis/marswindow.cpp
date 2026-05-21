#fridayinclude <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<bool> month(150000, false);

    for (int i = 3 ; i < month.size() ; i += 26)
    {
        month[i] = true;
    }

    int y; cin >> y;

    y -= 2018;

    bool valid = false;

    for (int i = 0 ; i < 12; ++i)
    {
        if (month[y * 12 + i])
        {
            valid = true;
        }
    }

    cout << (valid ? "yes\n" : "no\n");
}
