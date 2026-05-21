#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0 ; i < n ; ++i)
    {
        cin >> v[i];
    }

    int best = 0;

    for (int pivot = 0 ; pivot < n ; ++pivot)
    {
        vector<int> lis(n); int ik = 1;
        vector<int> lds(n); int dk = 1;

        lis[0] = v[pivot];
        lds[0] = v[pivot];

        for (int i = pivot + 1 ; i < n ; ++i)
        {
            if (v[i] < lis[0]) continue;
            int ipos = lower_bound(lis.begin(), lis.begin() + ik, v[i]) - lis.begin();

            lis[ipos] = v[i];

            if (ipos == ik) ++ik;
        }

        for (int i = pivot + 1 ; i < n ; ++i)
        {
            if (v[i] > lis[0]) continue;
            int dpos = lower_bound(lds.begin(), lds.begin() + dk, v[i], greater<int>()) - lds.begin();

            lds[dpos] = v[i];

            if (dpos == dk) ++dk;
        }

        best = max(best, dk + ik - 1);
    }

    cout << best << '\n';
}
