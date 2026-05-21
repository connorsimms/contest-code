#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        std::unordered_map<int, int> count;
        std::vector<int> vals(n);

        for (int i = 0 ; i < n ; ++i)
        {
            cin >> vals[i];
        }

        bool jolly = true;

        for (int i = 0 ; i < n  - 1; ++i)
        {
            int diff = abs(vals[i + 1] - vals[i]);

            if (diff > n - 1 || diff == 0)
            {
                jolly = false;
                break;
            }

            if (count[diff]) 
            { 
                jolly = false;
                break;
            }

            ++count[diff];
        }

        cout << (jolly ? "Jolly\n" : "Not jolly\n");
    }
}
