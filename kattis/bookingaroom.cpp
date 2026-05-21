#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n; int k; cin >> k;

    vector<bool> booked(n + 1);

    for (int i = 0 ; i < k ; ++i)
    {
        int x; cin >> x; booked[x] = true;
    }

    for (int i = 1; i <= n ; ++i)
    {
        if (!booked[i])
        {
            cout << i << '\n';
            return 0;
        }
    }
    
    cout << "too late\n";
}
