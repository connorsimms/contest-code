#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);

    for (int i = 0 ; i < n ; ++i)
    {
        cin >> v[i];
    }

    vector<int> left(n);
    vector<int> right(n);

    int m = v[0];
    for (int i = 0 ; i < n ; ++i)
    {
        m = max(m, v[i]);
        left[i] = m;
    }

    m = v.back();
    for (int i = n-1 ; i >= 0 ; --i)
    {
        m = min(m, v[i]);
        right[i] = m;
    }

    int ans{0};
    if (v[0] < right[1]) ++ans;
    for (int i = 1 ; i < n - 1 ; ++i)
    {
        if (left[i - 1] <= v[i] && v[i] < right[i + 1])
        {
            ++ans; 
        }
    }
    if (v.back() >= left[n - 2]) ++ans;

    cout << ans << '\n';
}
