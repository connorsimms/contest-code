#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int t; cin >> t;
    int M = 0, S = 0;
    while (t--)
    {
        int m; int s; cin >> m >> s;
        M += m; S += s;
    }

    if ( M * 60 >= S ) { cout << "measurement error\n"; return 0; }

    cout << fixed << setprecision(8) << (double)(S) / 60 / M << '\n';
}
