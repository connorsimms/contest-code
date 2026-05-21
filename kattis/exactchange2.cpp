#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T; cin >> T;
    while (T--)
    {
        int p; cin >> p;
        int n; cin >> n;

        int total = 0;
        vector<int> d(n);

        for (int i = 0 ; i < n ; ++i)
        {
            cin >> d[i]; 
            total += d[i];
        }

        vector<int> mem(total + 1, 1e9 + 1);

        mem[0] = 0;

        for (int i = 0 ; i < n ; ++i)
        {
            for (int j = total ; j >= d[i]; --j)
            {
                if (mem[j - d[i]] == 1e9 + 1) continue;

                mem[j] = min(mem[j], mem[j - d[i]] + 1);
            }
        }

        for (int i = p; i <= total; ++i)
        {
            if (mem[i] != 1e9 + 1)
            {
                cout << i << " " << mem[i] << '\n';
                break;
            }
        }
    }
}
