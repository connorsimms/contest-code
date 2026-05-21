#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n ; ++i) cin >> v[i];
    vector<int> b(n);
    for (int i = 0; i < n ; ++i) 
    {
        int x; cin >> x;
        b[x - 1] = i; // indexOf elements
    }

    int inv = 0;

    vector<int> w = v;

    auto merge = [&](int start, int mid, int end) {
        int l = start; int r = mid; int inv = 0; int idx = start;

        while (l != mid && r != end)
        {
            if (b[v[l] - 1] > b[v[r] - 1]) 
            {
                inv += mid - l;    
                w[idx++] = v[r++];
            }
            else
            {
                w[idx++] = v[l++];
            }
        }

        while (l != mid) { w[idx++] = v[l++]; }

        while (r != end) { w[idx++] = v[r++]; }

        for (int i = start ; i < end ; ++i)
        {
            v[i] = w[i];
        }

        return inv;
    };

    long long numInv = 0;

    auto mergeSort = [&](int start, int end, auto&& self) {
        if (end - start <= 1) return;

        int mid = start + (end - start) / 2;

        self(start, mid, self);
        self(mid, end, self);

        numInv += merge(start, mid, end);
    };

    mergeSort(0, v.size(), mergeSort);

    //cout << numInv << '\n';

    if (numInv % 2 == 0)
    {
        cout << "Possible\n";
    }
    else 
    {
        cout << "Impossible\n";
    }
}
