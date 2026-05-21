#include "bits/stdc++.h"

using namespace std;

int main()
{
    int K;
    cin >> K;
    
    int ans = K / 500;

    K %= 500;

    if(K > 400) { ++ans; }
    else if( K > 300) { ans += 2; }
    else if( K > 200) { ans += 2; }
    else if( K > 100) { ans++; }
    else { ans++; }
    
    cout << ans << '\n';
}
