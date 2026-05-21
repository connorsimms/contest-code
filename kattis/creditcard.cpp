#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int T; cin >> T;
    while (T--)
    {
        long double R, B, M; cin >> R >> B >> M;
        long long B_c = (long long)round(B * 100);
        long long M_c = (long long)round(M * 100);
        int month = 0;

        while (B_c > 0 && month <= 1200) { 
            if (month > 0) { B_c -= M_c; }

            if (B_c <= 0) { break; }

            long long cents = roundl((long double)B_c / 100 * R);

            B_c += cents;
            ++month;
        }

        if (month <= 1200) { cout << month << '\n'; }
        else { cout << "impossible\n"; }
    }
}
