#include <iostream>
using namespace std;

int main()
{
    int n1, n2; cin >> n1 >> n2;
    if(n1 == n2) { cout << 0 << '\n'; return 0 ; }

    if( abs(n2 - n1) < 180 ) { cout << n2 - n1 << '\n'; }
    else if (abs(n2 - n1) == 180) { cout << 180 << '\n'; }
    else {
        int comp = (360 - abs(n2 - n1));
        if (n2 - n1 > 0) { comp *= -1; }
        cout << comp << '\n';
    }
}
