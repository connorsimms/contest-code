#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int k; cin >> k; cout << k << " ";

        int ans = 0;

        vector<int> line(1);
        cin >> line[0]; 

        for (int i = 1 ; i < 20; ++i)
        {
            int x; cin >> x;

            auto it = upper_bound(line.begin(), line.end(), x);

            ans += (line.end() - it);

            line.insert(it, x);
        }
        cout << ans << '\n';
    }
}

