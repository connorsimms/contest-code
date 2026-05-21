#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, 
            tree_order_statistics_node_update> ost;

int main()
{
    int T; cin >> T;
    while (T--)
    {
        ost tree;
        long long ans = 0;

        int N; cin >> N;
        for (int i = 1; i <= N; ++i)
        {
            int x; cin >> x; tree.insert(make_pair(x,i));

            int med;

            if (i % 2)
            {
                med = tree.find_by_order(i / 2)->first;
            }
            else
            {
                med =   tree.find_by_order(i / 2 - 1)->first + 
                        tree.find_by_order(i / 2)->first;
                med /= 2;
            }

            ans += med;
        }
        cout << ans << '\n';
    }
}
