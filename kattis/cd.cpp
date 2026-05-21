#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int n, m;
    while ( cin >> n >> m && !(n == 0 && m == 0))
    {
        unordered_set<int> jack;
        for (int i = 0 ; i < n; ++i)
        {
            int x; cin >> x;
            jack.insert(x);
        }

        int ans = 0;

        for (int j = 0 ; j < m ; ++j)
        {
            int x; cin >> x;
            if (jack.count(x))
            {
                ++ans;
            }
        }

        cout << ans << '\n';
    }
}
