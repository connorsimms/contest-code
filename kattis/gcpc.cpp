#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

int main()
{
    struct cmp
    {
        unordered_map<int, pair<int, int>> score;

        bool operator() (const int& A, const int& B) const
        {
            const auto& [a1, b1] = score.at(A);
            const auto& [a2, b2] = score.at(B);

            if (a1 != a2) return a1 > a2;
            if (b1 != b2) return  b1 < b2;
            return A < B;
        }
    };

    typedef tree<int, null_type, cmp, rb_tree_tag,
                tree_order_statistics_node_update> ost;

    ost tree;

    int n, m; cin >> n >> m;

    for (int i = 1 ; i <= n ; ++i)
    {
        tree.get_cmp_fn().score[i]= make_pair(0,0);

        tree.insert(i);
    }

    for (int i = 0 ; i < m ; ++i)
    {
        int t, p; cin >> t >> p;

        tree.erase(t);

        tree.get_cmp_fn().score[t].first += 1;
        tree.get_cmp_fn().score[t].second += p;

        tree.insert(t);

        cout << tree.order_of_key(1) + 1 << '\n';
    }
}
