#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n, b; cin >> n >> b;
    vector<int> v(n);

    int bidx = -1;
    for (int i = 0 ; i < n ; ++i)
    {
        int x; cin >> x;
        if (x > b) v[i] = 1;
        if (x < b) v[i] = -1;
        if (x == b) 
        {
            bidx = i;
            v[i] = 0;
        }
    }

    map<int, int> left;
    map<int, int> right;

    int lsum = 0;
    for (int i = bidx - 1; i >= 0; --i)
    {
        lsum += v[i]; 

        ++left[lsum];
    }

    int rsum = 0;
    for (int i = bidx + 1; i < n; ++i)
    {
        rsum += v[i]; 

        ++right[rsum];
    }

    int ans = 0;

    for (int i = -n ; i < n; ++i)
    {
        ans += left[i] * right[-i];
    }

    ans += right[0];
   ans += left[0];

    cout << 1 + ans << '\n';
}
