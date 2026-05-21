#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, int> pos;

    int n; cin >> n;

    int awk = n;

    for (int i = 0 ; i < n; ++i)
    {
        int x; cin >> x;

        if (pos.count(x))
        {
            int dist = i - pos[x];
            awk = min(dist, awk);
        }

        pos[x] = i;
    }

    cout << awk << '\n';
}
