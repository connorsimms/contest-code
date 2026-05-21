#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<bool> bus(1004);
    for (int i = 0 ; i < n ; ++i)
    {
        int x; cin >> x;
        bus[x] = true;
    }

    bool seq = false;
    bool first = true;
    for (int i = 1; i < 1001; ++i)
    {
        if (!bus[i]) 
        {
            seq = false;
            continue;
        }

        if (bus[i] && bus[i - 1] && bus[i + 1])
        {
            seq = true;
            continue;
        }

        if (first)
            first = false;
        else if (seq && bus[i] && !bus[i + 1])
            cout << '-';
        else
            cout << ' ';
            
        cout << i;
    }
}
