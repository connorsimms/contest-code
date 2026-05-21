#include <bits/stdc++.h>
using namespace std;

int main()
{
    double EPS = 1e-9;
    double A, B, C; cin >> A >> B >> C;
    double I, J, K; cin >> I >> J >> K;

    double x = min(A/I, min(B/J, C/K));

    cout << fixed << setprecision(6) 
	<< abs(A - I * x) << " " << abs(B - J * x) << " " << abs(C - K * x) << '\n';
}
