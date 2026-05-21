#include <iostream>
using namespace std;

int main()
{
    int h, m; cin >> h >> m;
    int tm = h * 60 + m;

    tm = tm + 60 * 24 - 45;
    tm %= 60 * 24;

    cout << tm / 60 << " " << tm % 60 << '\n';
}
