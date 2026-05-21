#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int N; cin >> N;
    while (N--)
    {
        int b; double p; cin >> b >> p;

        double abpm = 60 / p;

        double A = 60 * b / p - abpm;
        double B = 60 * b / p;
        double C = 60 * b / p + abpm;

        cout << fixed << setprecision(4) << A << " " << B << " " << C << '\n';
    }
}
