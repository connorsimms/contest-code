#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    vector<long long> cits;

    for(int i = 0 ; i < n ; ++i)
    {
        long long x; cin >> x;
        cits.push_back(x);
    }

    sort(cits.begin(), cits.end());

    int h = 0;
    for(int i = cits.size() - 1; i >= 0; --i)
    {
        long long papers = cits.size() - i;
        long long cc = cits[i];

        if (cc >= papers)
        {
            h = papers;
        } else 
        {
            break;
        }
    }
    cout << h << '\n';
}
