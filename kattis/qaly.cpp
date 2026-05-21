#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    double q = 0;
    for(int i = 0 ; i < n ;++i)
    {
	double qol, g; cin >> qol >> g;
	q += qol * g;
    }
    cout << setprecision(6) << q << '\n';
}
