#include <bits/stdc++.h>
using namespace std;

int main()
{
    double d, s; cin >> d >> s;

    // find a such that 
    //
    // a + s = a * (e^{d/2a} + e^-{d/2a}) / 2
    //
    // output 2a * (e^{d/2a} - e^-{d/2a}) / 2

    double lo = 0.0, hi = 1e12;
    double a;

    int i = 0; 
    while (++i < 1000)
    {   
        a = (hi + lo) / 2;

        double x = a + s;
        double y = a * cosh(d / (2 * a));

        if (y > x)
        {
            lo = a;
        }
        else
        {
            hi = a;
        }
    }

    cout << fixed << setprecision(8) << 2 * a * sinh(d / (2 * a)) << '\n';
}
