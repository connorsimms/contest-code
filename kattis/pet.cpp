#include <iostream>
using namespace std;

int main()
{
    int winner = -1; int best = 0;

    for (int i = 0 ; i < 5; ++i)
    {
        int sum = 0;
        for (int j = 0; j < 4; ++j)
        {
            int s; cin >> s;
            
            sum += s;
        }

        if (sum > best)
        {
            best = sum;
            winner = i + 1; 
        }
    }
    
    cout << winner << " " << best << '\n';
}
