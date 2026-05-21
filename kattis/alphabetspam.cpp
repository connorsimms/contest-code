#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string line; getline(cin, line);

    int low{0}, up{0}, white{0};

    for (auto x : line)
    {
        if (x >= 'A' && x <= 'Z') { ++up; } 
        if (x >= 'a' && x <= 'z') { ++low; } 
        if (x == '_') { ++white; } 
    }

    int sym = line.size() - low - up - white;

    cout << fixed << setprecision(8);

    cout << (double)white / line.size() << '\n';
    cout << (double)low / line.size() << '\n';
    cout << (double)up / line.size() << '\n';
    cout << (double)sym / line.size() << '\n';
}
