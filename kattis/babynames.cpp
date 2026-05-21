#include <bits/stdc++.h>
#include <bits/extc++.h> // pbds 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<string, null_type, less<string>, 
        rb_tree_tag, tree_order_statistics_node_update> ost;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cmd;

    ost m;
    ost f;

    while (cin >> cmd && cmd != 0)
    {
        switch (cmd)
        {
            case 1:
            {
                string name; int gen;
                cin >> name >> gen;
                if (gen == 1) { m.insert(name); }
                else if (gen == 2) { f.insert(name); }
                break;
            }
            case 2:
            {
                string name; cin >> name; 
                if (!m.erase(name)) f.erase(name);
                break;
            }
            case 3:
            {
                string start, end; int gen;
                cin >> start >> end >> gen;

                int ans = 0;

                if (start == end) 
                {
                    cout << ans << '\n';
                    break;
                }

                if (gen == 0 || gen == 1) 
                { 
                    ans += m.order_of_key(end) - m.order_of_key(start);
                }
                if (gen == 0 || gen == 2) 
                { 
                    ans += f.order_of_key(end) - f.order_of_key(start);
                }

                cout << ans << '\n';

                break;
            }
        }
    }
}
