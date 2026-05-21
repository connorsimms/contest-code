#include <iostream>

using namespace std;

int main()
{
    int T; cin >> T;
    while (T--)
    {
        int a, b; cin >> a >> b;

        if (a < b) { cout << "impossible\n"; continue; }

        int x = a + b; int y = a - b;

        if ( x / 2 + y / 2 != a || x / 2 - y / 2 != b) { cout << "impossible\n"; continue; }

        cout << x / 2 << " " << y / 2 << '\n';
    }
}

