#include <iostream>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;

int main()
{
    map<int, int> A; A[0] = 0;
    map<int, int, greater<int>> B; B[0] = 0;
    
    int n; cin >> n;
    for (int i = 0 ; i < n ; ++i)
    {
        int a, b; cin >> a >> b;
        ++A[a]; ++B[b];

        int largest = 0;

        auto ita = A.begin(); int aleft = ita->second;
        auto itb = B.begin(); int bleft = itb->second;

        while (ita != A.end() && itb != B.end())
        {
            if (aleft == 0)
            {
                ++ita;
                aleft = ita->second;
            }

            if (bleft == 0)
            {
                ++itb;
                bleft = itb->second;
            }

            int sub = min(aleft, bleft);

            aleft -= sub;
            bleft -= sub;

            largest = max(largest, ita->first + itb->first);
        }
        cout << largest << '\n';
    }
}

