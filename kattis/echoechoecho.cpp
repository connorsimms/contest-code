#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p, a, b, c, d, n;
    cin >> p >> a >> b >> c >> d >> n;
    
    vector<double> maxPrice(n + 1);
    vector<double> minPrice(n + 1);
    
    double maxSoFar = 0.0;
    for(int i = 1 ; i <= n; ++i) {
        double price = p * (sin(a * i + b) + cos(c * i + d) + 2);
        maxSoFar = max(maxSoFar, price);
        
        maxPrice[i] = maxSoFar;
    }
    
    double minSoFar = 1e9 + 0.0;
    for(int i = n ; i >= 1; --i) {
        double price = p * (sin(a * i + b) + cos(c * i + d) + 2);
        minSoFar = min(minSoFar, price);
        
        minPrice[i] = minSoFar;
    }
    
    double largestDecline = 0.0;
    for(int i = 1 ; i <= n; ++i) {
        largestDecline = max(largestDecline, maxPrice[i] - minPrice[i]);
    }
    
    cout << fixed << setprecision(6) << largestDecline << '\n';
}
