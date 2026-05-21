#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    
    vector<int> tl(100001, 0);
    int ans = 0;

    for (int i = 0 ; i < n ; ++i)
    {
        int t; cin >> t;

        for (int j = t; j < tl.size() && j < t + 1000; ++j)
        {
            ++tl[j];
            ans = max(ans, tl[j] / k + (tl[j] % k != 0));
        }
    }

    cout << ans << '\n';
}
