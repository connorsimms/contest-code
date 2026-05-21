#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T; cin >> T;

    for (int tc = 1; tc <= T; ++tc)
    {
        cout << "Case #" << tc << ": ";

        int N, K; cin >> N >> K;
        
        if ((K+1) % ((1 << N)) == 0)
        {
            cout << "ON\n";
        }
        else
        {
            cout << "OFF\n";
        }
    }
}
