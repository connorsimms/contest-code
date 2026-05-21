#include <bits/stdc++.h>
using namespace std;

int main()
{
    double C, X, M; cin >> C >> X >> M;
    C /= 2;
    int maxSpeed = 0;
    for(int i = 0 ; i < 6; ++i)
    {
	int mph; cin >> mph;
	double mpg; cin >> mpg;

	double need = M / mph; // hours
	double rate = mph / mpg + X; // gallons per hour
	if(C > rate * need) { maxSpeed = max(maxSpeed, mph); }
    }

    if(maxSpeed == 0) { cout << "NO\n"; }
    else { cout << "YES " << maxSpeed << '\n'; }
}
