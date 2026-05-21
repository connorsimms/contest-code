#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> d(n);
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> d[i];
    }

    int largest = d[d.size() - 1] + d[d.size() - 2];

    vector<int> mem(largest + 1, 1e9 + 1);
    mem[0] = 0;

    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j + d[i] <= largest ; ++j)
        {
            if (mem[j] == 1e9 + 1) continue;

            mem[j + d[i]] = min(mem[j + d[i]], mem[j] + 1);
        }
    }

    for (int i = d[1] ; i <= largest; ++i)
    {
        int amount = i;
        int greed = 0;
        for (int j = n - 1; amount > 0 && j >= 0; --j)
        {
            greed += amount / d[j];
            amount %= d[j];
        }

        if (greed != mem[i])
        {
            cout << "non-canonical\n";
            return 0;
        }
    }

    cout << "canonical\n";
}
