#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a0, a1, a2, a3, b0, b1, b2, b3;
    while(cin >> a0 >> a1 >> a2 >> a3 >> b0 >> b1 >> b2 >> b3) 
    {
	cout << a0 << " " << a1 << " " << a2 << " " << a3 << '\n' << b0 << " " << b1 << " " << b2 << " " << b3 << '\n';
        double da2 = a1; // c
        double da1 = 2 * a2; // b
        double da0 = 3 * a3; // a
        
        double db2 = b1;
        double db1 = 2 * b2;
        double db0 = 3 * b3;
        
        double roota1 = (-1 * da1 + sqrt(da1 * da1 - 4 * da0 * da2)) / (2 * da0);
        double roota2 = (-1 * da1 - sqrt(da1 * da1 - 4 * da0 * da2)) / (2 * da0);

        double rootb1 = (-1 * db1 + sqrt(db1 * db1 - 4 * db0 * db2)) / (2 * db0);
        double rootb2 = (-1 * db1 - sqrt(db1 * db1 - 4 * db0 * db2)) / (2 * db0);
        
        int va1, va2, vb1, vb2;
        
	cout << roota1 << " " << roota2 << " " << rootb1 << " " << rootb2 << '\n';
    }
}
