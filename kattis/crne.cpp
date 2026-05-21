#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    
    if(n == 1) { cout << 2 << '\n'; return 0; }
    
    if(n % 2 == 0) { cout << (n / 2 + 1) * (n / 2 + 1) << '\n'; }
    else { cout << ((n-1)/2 + 1) * ((n-1)/2 + 1) + n - 1 << '\n'; }
    
    return 0;
}
