#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<long long> v(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    long long d = 0;
    for (int i = 2; i < n; i += 3)
    {
        d += v[i]; 
    }

    cout << d << '\n';
}
