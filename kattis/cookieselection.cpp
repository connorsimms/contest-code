#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
            tree_order_statistics_node_update> ost;


int main()
{
    string line;

    ost tree;

    int id = 0;
    int size = 0;

    while (getline(cin, line))
    {
        if (line[0] == '#')
        {
            auto it = tree.find_by_order(size / 2);
            int med = it->first;
            tree.erase(it);

            cout << med << '\n';
            --size;
        }
        else
        {
            stringstream ss{ line };
            int d; ss >> d;

            tree.insert(make_pair(d, ++id));
            ++size;
        }
    }
}

