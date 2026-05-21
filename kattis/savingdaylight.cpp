#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string line;
    while (getline(cin, line))
    {
        stringstream ss{ line };
        string m, d, y;
        ss >> m >> d >> y;

        int h1, m1, h2, m2;
        char delim;

        ss >> h1 >> delim >> m1 >> h2 >> delim >> m2;

        int h = h2 - h1;
        int min = m2 - m1;

        int agg = h * 60 + min;

        cout << m << " " << d << " " << y << " " << agg / 60 << " hours " << agg % 60 << " minutes\n";
    }
}
