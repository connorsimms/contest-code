#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x0, y0; cin >> x0 >> y0;
    int xf, yf; cin >> xf >> yf;
    int n; cin >> n;
    if(abs(x0 - xf) + abs(y0 - yf) > n) { cout << "N\n"; return 0; }
    cout << ((((abs(x0 - xf) + abs(y0 - yf)) % 2) == (n % 2)) ? "Y\n" : "N\n");
}
