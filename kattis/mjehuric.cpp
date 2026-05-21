#include <iostream>
#include <vector>
using namespace std;

int main()
{
    array<int, 5> a;
    for (int i = 0 ; i < 5; ++i)
    {
        cin >> a[i];
    }

    bool ordered = false;

    while (!ordered)
    {
        ordered = true;
        for (int i = 0 ; i < 4; ++i)
        {
            if (a[i] > a[i + 1]) 
            {
                ordered = false;
                swap(a[i], a[i + 1]);
                for (auto x : a) cout << x << " ";
                cout << '\n';
            }
        }
    }
}
