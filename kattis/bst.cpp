#include <iostream>
#include <vector>
#include <iterator>
#include <set>
using namespace std;

int main()
{
    int n; cin >> n;

    set<int> s;
    vector<int> dep(n + 1);

    int val; cin >> val;
    s.insert(val);

    long long ans = 0;
    cout << ans << '\n';

    for (int i = 1 ; i < n; ++i)
    {
        cin >> val;

        auto [it, _] = s.insert(val);

        auto suc = next(it, 1);

        if (it != s.begin())
        {
            auto pre = next(it, -1);
            dep[val] = dep[*pre] + 1;
        }
        if (suc != s.end())
        {
            dep[val] = max(dep[val], dep[*suc] + 1);
        }

        ans += dep[val];
        
        cout << ans << '\n';
    }
}
